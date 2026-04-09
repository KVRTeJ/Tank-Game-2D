import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: movableRect
        color: "black"

        width: 50
        height: 50
        visible: true
        focus: true

        Keys.onPressed: (event) => {
            let step = 10

            if (event.key === Qt.Key_Left)
                movableRect.x -= step
            else if (event.key === Qt.Key_Right)
                movableRect.x += step
            else if (event.key === Qt.Key_Up)
                movableRect.y -= step
            else if (event.key === Qt.Key_Down)
                movableRect.y += step
        }
        Keys.onReleased: (event) => {
            let step = 10

            if (event.key === Qt.Key_Left)
                movableRect.x -= step
            else if (event.key === Qt.Key_Right)
                movableRect.x += step
            else if (event.key === Qt.Key_Up)
                movableRect.y -= step
            else if (event.key === Qt.Key_Down)
                movableRect.y += step
        }
    }
}
