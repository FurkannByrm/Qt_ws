import QtQuick 2.1

Rectangle {
    id: root
    width: joystick.width
    height: joystick.height
    color: "transparent"

    signal joystick_moved(double x, double y)

    Image {
        id: joystick
        source: "background.png"
        anchors.centerIn: parent

        ParallelAnimation {
            id: returnAnimation
            NumberAnimation { target: thumb.anchors; property: "horizontalCenterOffset"; to: 0; duration: 200; easing.type: Easing.OutSine }
            NumberAnimation { target: thumb.anchors; property: "verticalCenterOffset"; to: 0; duration: 200; easing.type: Easing.OutSine }
        }

        MouseArea {
            id: mouse
            anchors.fill: parent
            property real distanceBound: width * 0.5 - thumb.width * 0.5
            property double signal_x: (mouseX - width / 2) / distanceBound
            property double signal_y: -(mouseY - height / 2) / distanceBound

            onPressed: {
                returnAnimation.stop()
            }

            onReleased: {
                returnAnimation.restart()
                joystick_moved(0, 0)
            }

            onPositionChanged: {
                var mcx = mouseX - width * 0.5
                var mcy = mouseY - height * 0.5
                var distance = Math.sqrt(mcx * mcx + mcy * mcy)

                if (distance < distanceBound) {
                    thumb.anchors.horizontalCenterOffset = mcx
                    thumb.anchors.verticalCenterOffset = mcy
                } else {
                    var angle = Math.atan2(mcy, mcx)
                    thumb.anchors.horizontalCenterOffset = Math.cos(angle) * distanceBound
                    thumb.anchors.verticalCenterOffset = Math.sin(angle) * distanceBound
                }

                joystick_moved(signal_x, signal_y)
            }
        }

        Image {
            id: thumb
            source: "finger.png"
            anchors.centerIn: parent
        }
    }
}
