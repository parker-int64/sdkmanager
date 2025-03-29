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
}

void WSLManager::processWSLInfoStr(const QString &str)
{
    QRegularExpression regex("[:：]|\r\n");
    QStringList list = str.split(regex, Qt::SkipEmptyParts);

    QVariantMap m; // JSON object
    // output
    for (int i = 0; i < list.size() - 1; i += 2)
    {
        QString key, value;
        if (i == 0)
        {
            QStringList t = value.split(".");
            for (auto j : t)
            {
                m_wslVersion.emplace_back(j.toInt());
            }
        }

        key = list[i].trimmed();
        value = list[i + 1].trimmed();
        m.insert(key, value);
    }

    emit wslInfoReceived(m);
}

void WSLManager::handleStdOutput()
{
    QStringDecoder decoder(QStringDecoder::Utf16LE); // Decode UTF-16LE
    QByteArray rawArray = m_process.readAllStandardOutput();
    QString output = decoder.decode(rawArray);
    if (!rawArray.isEmpty())
    {
        qDebug() << "[Output]" << output.trimmed();
        m_stdOutput = output;

        switch (m_curCmd)
        {
        case WSLCmd::GetWSLInfo:
            processWSLInfoStr(output);
            break;

        default:
            break;
        }
    }
}

void WSLManager::handleStdError()
{
    QStringDecoder decoder(QStringDecoder::Utf16LE); // Decode UTF-16LE
    QByteArray errArray = m_process.readAllStandardError();
    QString errOutput = decoder.decode(errArray);
    if (!errOutput.isEmpty())
    {
        qWarning() << "[Error]" << errOutput.trimmed();
        m_errOutput = errOutput;
    }
}