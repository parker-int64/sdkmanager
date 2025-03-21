#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWebEngineQuick>
#include <QtWebChannel/QtWebChannel>
#include "wslcontroller.h"
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
    
    QWebChannel *channel = new QWebChannel();

    WSLController *controller = new WSLController();

    if(!controller) {
        return -1;
    }

    channel->registerObject("wslctrl", controller);
    // access through qml
    // engine.rootContext()->setContextProperty("controller", controller);

    engine.loadFromModule("SDKManager", "Main");

    return app.exec();
}
