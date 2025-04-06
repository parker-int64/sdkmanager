#ifndef APP_CONTROLLER_H
#define APP_CONTROLLER_H

#include <QObject>

class AppController : public QObject
{
    Q_OBJECT
private:
    /* data */
public:
    explicit AppController(QObject *parent = nullptr);
    virtual ~AppController();

public slots:
    void restartApp();
    void closeApp();
    void getSysInfo(); // Info for diagnose
};

#endif
