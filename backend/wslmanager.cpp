#include "wslmanager.h"
#include <QDebug>
#include <QByteArray>
#include <QStringDecoder>

WSLManager::WSLManager(QObject *parent)
    : QObject(parent),
      m_process()
{
    // connect(m_process, SIGNAL(readyReadStandardOutput()), this, SLOT(handleStdOutput()));
}

WSLManager::~WSLManager()
{
}

void WSLManager::checkWSLVer()
{
    const QString command = "wsl -l";
    handlePSCmd(command);
}

/// @brief
/// @param command
/// @return
bool WSLManager::handlePSCmd(const QString &command)
{

    m_process.start("powershell.exe", {"-Command", "wsl", "-v"});
    m_process.setReadChannel(QProcess::StandardOutput);
    qDebug() << "Calling: " << __FUNCTION__ << "Variable 'fullcommand': " << command << Qt::endl;

    if (!m_process.waitForFinished())
    {
        qWarning() << "Failed to execute command:" << command << Qt::endl;
        return false;
    }

    QByteArray rawArray = m_process.readAllStandardOutput();
    QByteArray errorOutput = m_process.readAllStandardError();

    QStringDecoder decoder(QStringDecoder::Utf16LE); // Decode UTF-16LE

    QString output = decoder.decode(rawArray);

    if (!rawArray.isEmpty())
    {
        qDebug() << "[Output]" << output.trimmed();
        return true;
    }

    if (!errorOutput.isEmpty())
    {
        qWarning() << "[Error]" << QString::fromUtf8(errorOutput).trimmed();
        return false;
    }

    return false;
}

void WSLManager::handleStdOutput()
{
    // QTextCodec
}