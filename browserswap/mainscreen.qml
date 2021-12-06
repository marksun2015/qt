import QtQuick 2.0  
import Weintek.Browser 1.0

Rectangle {  
    id: root  
    width: 600  
    height: 400  
    property int testcount: 0

    Loader {  
        id: dialLoader  
        anchors.left: parent.left  
        anchors.right: parent.right  
        anchors.top: parent.top  
        anchors.bottom: browser1Button.top  
    }  

    Timer {
            id: timer_button;
            interval: 1000;
            repeat: true
            running: false
            triggeredOnStart: true
            onTriggered: {
                console.log("timer")
                testcount++;
                if((testcount%2) == 0)
                    root.state = "browser1"; 
                else 
                    root.state = "browser2"; 
            }
    }

    Component.onCompleted: { 
       timer_button.start();
    }

    Rectangle {  
        id: browser1Button  
        anchors.left: parent.left  
        anchors.bottom: parent.bottom  
        color: "gray"  
        width: parent.width/2  
        height: 100  

        Text {  
            anchors.centerIn: parent  
                text: "Analog"  
        }  

        MouseArea {  
            anchors.fill: parent  
            onClicked: root.state = "browser1";  
        }  
    }  

    Rectangle {  
        id: browser2Button  

        anchors.right: parent.right  
        anchors.bottom: parent.bottom  

        color: "gray"  

        width: parent.width/2  
        height: 100  

        Text {  
            anchors.centerIn: parent  
                text: "Digital"  
        }  

        MouseArea {  
            anchors.fill: parent  
            onClicked: root.state = "browser2";  
        }  
    }  

    state: "browser1"  
    states: [  
        State {  
            name: "browser1"  
            PropertyChanges { target: browser1Button; color: "green"; }  
            PropertyChanges { target: dialLoader; source: "browser1.qml"; }  
        },

        State {  
        name: "browser2"  
            PropertyChanges { target: browser2Button; color: "green"; }  
            PropertyChanges { target: dialLoader; source: "browser2.qml"; }  
        }  
    ]  
}  
