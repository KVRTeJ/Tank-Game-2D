#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "include/systems/input/keyhandler.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<KeyHandler>("keyHandler", 1, 0, "KeyHandler");
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("tank_game_2d", "Main");

    return QCoreApplication::exec();
}
