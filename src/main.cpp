#include "include/core/eventbus.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>

struct Sub1 {
    int a = 1;

    void print(int a) {
        std::cout << "Sub1 - " << a << std::endl;
    }
    void foo(EventBus& bus) {
        bus.subscribe<int>([this](const int& arg) {
            this->print(arg);
        });
    }
};

struct Sub2 {
    int a = 1;

    void print(int a) {
        std::cout << "Sub2 - " << a << std::endl;
    }
    void foo(EventBus& bus) {
        bus.subscribe<int>([this](const int& arg) {
            this->print(arg);
        });
    }
};

struct Sub3 {
    float a = 1;

    void print(float a) {
        std::cout << "Sub3 - " << a << std::endl;
    }
    void foo(EventBus& bus) {
        bus.subscribe<float>([this](const float& arg) {
            this->print(arg);
        });
    }
};

int main(int argc, char *argv[])
{
    EventBus mainBus;
    Sub1 a;
    Sub2 b;
    Sub3 c;

    a.foo(mainBus);
    b.foo(mainBus);
    c.foo(mainBus);

    mainBus.publish<float>(12);
    mainBus.publish<int>(1);
    mainBus.publish<int>(2);

    return -1;

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("tank_game_2d", "Main");

    return QCoreApplication::exec();
}
