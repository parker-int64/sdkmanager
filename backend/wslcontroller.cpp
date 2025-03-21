#include "wslcontroller.h"
#include <QProcess>
#include <QDebug>

WSLController::WSLController(QObject *parent)
    : QObject(parent)
{
}

WSLController::~WSLController()
{
}

void WSLController::startWSL()
{
    const QString command = "wsl --set-default-version 2";
    handlePowerShellCommand(command);
    emit wslStarted();
}

void WSLController::handlePowerShellCommand(const QString &command)
{
    QProcess process;

    QString fullCommand = QString("powershell.exe -Command \"%1\"").arg(command);

    process.start(fullCommand);
    if (!process.waitForFinished())
    {
        qWarning() << "Failed to execute command:" << command;
        return;
    }

    QString output = process.readAllStandardOutput();
    QString errorOutput = process.readAllStandardError();

    if (!output.isEmpty())
    {
        qDebug() << "[Output]" << output.trimmed();
    }

    if (!errorOutput.isEmpty())
    {
        qWarning() << "[Error]" << errorOutput.trimmed();
    }
}