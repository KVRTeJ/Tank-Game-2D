import QtQuick
import QtQuick.Controls

import keyHandler

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Dial {
        id: movableRect

        width: 50
        height: 50
        visible: true
        focus: true

        KeyHandler {
            id: keyHandler
        }

        Keys.onPressed: (event) => {
            if (event.isAutoRepeat)
                return;

            keyHandler.handleKeyPressed(event.key, event.modifiers)
        }
        Keys.onReleased: (event) => {
            if (event.isAutoRepeat)
                return;

            keyHandler.handleKeyReleased(event.key, event.modifiers)
        }
    }
}
