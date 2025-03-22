#ifndef WSLMANAGER_H
#define WSLMANAGER_H

#include <QObject>
#include <QString>

class WSLManager : public QObject
{
    Q_OBJECT

public:
    explicit WSLManager(QObject *parent = nullptr);
    virtual ~WSLManager();

    Q_SIGNAL void wslStarted();
    Q_SLOT void startWSL();

private:
    void handlePowerShellCommand(const QString &cmd);
};

#endif // WSLMANAGER_H
