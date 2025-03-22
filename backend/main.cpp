#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngineQuick>
#include <QtWebChannel/QtWebChannel>
#include "wslmanager.h"
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

    WSLManager *controller = new WSLManager();
    qmlRegisterType<WSLManager>("com.seeed.wsl", 1, 0, "WSLManager");
    // access through qml
    engine.rootContext()->setContextProperty("controller", controller);

    engine.loadFromModule("SDKManager", "Main");

    return app.exec();
}
