#pragma once

#include <QObject>
#include <qdebug.h>
#include <QThread>
#include <QSet>

class KeyHandler : public QObject {
    Q_OBJECT
public:
    KeyHandler() = default;
    ~KeyHandler() = default;

    Q_INVOKABLE void handleKeyPressed(Qt::Key key, Qt::KeyboardModifiers modifiers) {
        _pressed.insert(key);
    };

    Q_INVOKABLE void handleKeyReleased(Qt::Key key, Qt::KeyboardModifiers modifiers) {
        _pressed.remove(key);
    };

private:
    QSet<Qt::Key> _pressed;
};
