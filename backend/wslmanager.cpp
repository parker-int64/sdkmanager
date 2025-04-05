#include "wslmanager.h"
#include <QDebug>
#include <QByteArray>
#include <QStringDecoder>
#include <QRegularExpression>
#include <QregularExpressionMatchIterator>

WSLManager::WSLManager(QObject *parent)
    : QObject(parent),
      m_process(),
      m_stdOutput(),
      m_errOutput()
{

    m_process.setReadChannel(QProcess::StandardOutput);
    // Connect the signals to the slots
    connect(&m_process, &QProcess::readyReadStandardOutput, this, &WSLManager::handleStdOutput);
    connect(&m_process, &QProcess::readyReadStandardError, this, &WSLManager::handleStdError);

    // Connect the finished signal to a lambda function
    connect(&m_process, &QProcess::finished, this, [this](int exitCode, QProcess::ExitStatus exitStatus)
            {
        if (exitStatus == QProcess::NormalExit && exitCode == 0)
        {
            qDebug() << "Process finished successfully.";
        }
        else
        {
            qWarning() << "Process finished with error. Exit code:" << exitCode;
        } });
}

WSLManager::~WSLManager()
{
}

void WSLManager::getWSLInfo()
{
    m_curCmd = WSLCmd::GetWSLInfo;
    m_process.start("powershell.exe", {"-Command", "wsl", "-v"});
    m_process.waitForStarted();  // Sync
    m_process.waitForFinished(); // Sync
}

void WSLManager::processWSLInfoStr(const QString &str)
{
    QRegularExpression regex("[:：]|\r\n");
    QStringList list = str.split(regex, Qt::SkipEmptyParts);

    QVariantMap m; // JSON object
    QString key, value;
    // output
    for (int i = 0; i < list.size() - 1; i += 2)
    {
        key = list[i].trimmed();
        value = list[i + 1].trimmed();
        m.insert(key, value);
    }

    emit wslInfoReceived(m); // Send the QVariantMap object to frontend
}

void WSLManager::processWSLDistro(const QString &str)
{
    QRegularExpression regex("\r\n");
    QStringList list = str.split(regex, Qt::SkipEmptyParts);
    QVariantMap d;

    for (size_t i = 0; i < list.size(); ++i)
    {
        d.insert(QString::number(i), list[i]);
    }

    emit wslDistroReceived(d); // Send the QVariantMap object to frontend
}

void WSLManager::processWSLRunHello(const QString &str)
{
    if (str != "hello\n")
    {
        return;
    }
    emit wslHelloReceived(str);
}

void WSLManager::getWSLDistro()
{
    m_curCmd = WSLCmd::GetWSLDistros;
    m_process.start("powershell.exe", {"-Command", "wsl", "-l", "--quiet"});
    m_process.waitForStarted();  // Sync
    m_process.waitForFinished(); // Sync
}

void WSLManager::runDistroHello()
{
    m_curCmd = WSLCmd::EchoHello;
    m_process.start("wsl", {"-d", "Ubuntu-22.04", "bash", "-c", "echo hello"});
}

QString WSLManager::decodeOutput(const QByteArray &array, WSLCmd cmd)
{
    QStringDecoder decoder;
    switch (cmd)
    {
    case WSLCmd::EchoHello:
        decoder = QStringDecoder(QStringDecoder::Utf8);
        break;
    case WSLCmd::GetWSLInfo:
        [[fallthrough]]; // fall through
    case WSLCmd::GetWSLDistros:
        [[fallthrough]]; // fall through
    default:
        decoder = QStringDecoder(QStringDecoder::Utf16LE);
        break;
    }

    return decoder.decode(array);
}

void WSLManager::handleStdOutput()
{
    QByteArray rawArray = m_process.readAllStandardOutput();
    QString output = decodeOutput(rawArray, m_curCmd);

    if (rawArray.isEmpty())
    {
        qWarning() << "Reading empty output." << Qt::endl;
        return;
    }

    qDebug() << "[Output]" << output.trimmed();
    m_stdOutput = output;

    switch (m_curCmd)
    {
    case WSLCmd::GetWSLInfo:
        processWSLInfoStr(output);
        break;
    case WSLCmd::GetWSLDistros:
        processWSLDistro(output);
        break;
    case WSLCmd::EchoHello:
        processWSLRunHello(output);
        break;
    default:
        break;
    }
}

void WSLManager::handleStdError()
{
    QByteArray errArray = m_process.readAllStandardError();
    QString errOutput = decodeOutput(errArray, m_curCmd);

    if (errOutput.isEmpty())
    {
        qWarning() << "Reading empty error output." << Qt::endl;
        return;
    }

    qWarning() << "[Error] " << errOutput.trimmed();
    m_errOutput = errOutput;
    QString e = QString("Error occurred during executing command '%1':\n").arg(m_errOutput);

    emit wslErrorReceived(e);
}