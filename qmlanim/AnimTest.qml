import QtQuick 2.4

Item {
    width: 640
    height: 480

    AnimatedImage {
        id: anim
        anchors.fill: parent
        source: "matrix.gif"
        playing: false
    }

    MouseArea {
        anchors.fill: parent
        onClicked: anim.playing =true;
    }
}
