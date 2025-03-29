#ifndef WSLMANAGER_H
#define WSLMANAGER_H

#include <QObject>
#include <QString>
#include <QProcess>
#include <QVariant>
#include <QMap>
class WSLManager : public QObject
{
    Q_OBJECT

public:
    explicit WSLManager(QObject *parent = nullptr);
    virtual ~WSLManager();

    enum class WSLCmd
    {
        GetWSLInfo,
        GetWSLDistros,
    };

signals:
    void wslInfoReceived(const QVariantMap &obj);

public slots:
    void getWSLInfo();
    void handleStdOutput();
    void handleStdError();

private:
    bool handlePSCmd(const QString &cmd);
    void processWSLInfoStr(const QString &str);

    QProcess m_process;
    QString m_stdOutput;
    QString m_errOutput;
    WSLCmd m_curCmd;           // current wsl command, flag variable for different output
    QVariantList m_wslVersion; // A list contain version with numbers
    QString m_wslDefaultDistro;
    QStringList m_wslDistros;
};

#endif // WSLMANAGER_H
