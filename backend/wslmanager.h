#ifndef WSLMANAGER_H
#define WSLMANAGER_H

#include <QObject>
#include <QString>
#include <QProcess>

class WSLManager : public QObject
{
    Q_OBJECT

public:
    explicit WSLManager(QObject *parent = nullptr);
    virtual ~WSLManager();

public slots:
    void checkWSLVer();
    void handleStdOutput();

private:
    bool handlePSCmd(const QString &cmd);

    QProcess m_process;
};

#endif // WSLMANAGER_H
