#ifndef WSLCONTROLLER_H
#define WSLCONTROLLER_H

#include <QObject>
#include <QString>

class WSLController : public QObject
{
    Q_OBJECT

public:
    explicit WSLController(QObject *parent = nullptr);
    virtual ~WSLController();

    Q_SIGNAL void wslStarted();
    Q_SLOT void startWSL();

private:
    void handlePowerShellCommand(const QString &cmd);
};

#endif

