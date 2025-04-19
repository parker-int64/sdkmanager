#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngineQuick>
#include <QtWebChannel/QtWebChannel>
#include "wslmanager.h"
#include "appcontroller.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QtWebEngineQuick::initialize();
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []()
        { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    // These controller classes will be initialized in QML
    // And accessible from frontend
    qmlRegisterType<WSLManager>("com.seeed.wsl", 1, 0, "WSLManager");
    qmlRegisterType<AppController>("com.seeed.appctrl", 1, 0, "AppController");

    engine.loadFromModule("SDKManager", "Main");

    return app.exec();
}
