#include "wslmanager.h"
#include <QProcess>
#include <QDebug>

WSLManager::WSLManager(QObject *parent)
    : QObject(parent)
{
    // connect(this, SIGNAL(wslStarted), this, SLOT(startWSL));
}

WSLManager::~WSLManager()
{
}

void WSLManager::startWSL()
{
    const QString command = "wsl -l";
    handlePowerShellCommand(command);
    emit wslStarted();
}

void WSLManager::handlePowerShellCommand(const QString &command)
{
    QProcess process;

    QString fullCommand = QString("powershell.exe -Command '%1'").arg(command);

    qDebug() << "Calling: " << __FUNCTION__ << "Variable 'fullcommand': " << fullCommand;

    process.start(fullCommand);
    if (!process.waitForFinished())
    {
        qWarning() << "Failed to execute command:" << command;
        return;
    }

    QString rawArray = process.readAllStandardOutput();
    QString errorOutput = process.readAllStandardError();

    if (!rawArray.isEmpty())
    {
        qDebug() << "[Output]" << rawArray.trimmed();
    }

    if (!errorOutput.isEmpty())
    {
        qWarning() << "[Error]" << errorOutput.trimmed();
    }
}