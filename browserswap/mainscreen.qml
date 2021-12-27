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
            interval: 5000;
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
        width: parent.width/4  
        height: 80  

        Text {  
            anchors.centerIn: parent  
            text: "Browser1"  
        }  

        MouseArea {  
            anchors.fill: parent  
            onClicked: root.state = "browser1";  
        }  
    }  

    Rectangle {  
        id: startButton
        anchors.left: browser1Button.right  
        anchors.bottom: parent.bottom  
        color: "green"  

        width: parent.width/4  
        height: 80  

        Text {  
            anchors.centerIn: parent  
            text: "Sart"  
        }  

        MouseArea {  
            anchors.fill: parent  
            onClicked: {  
       		    timer_button.start();
	        }
        }  
    }
 
    Rectangle {  
        id: stopButton
        anchors.right: browser2Button.left  
        anchors.bottom: parent.bottom  
        color: "red"  

        width: parent.width/4  
        height: 80  

        Text {  
            anchors.centerIn: parent  
            text: "Stop"  
        }  

        MouseArea {  
            anchors.fill: parent  
            onClicked: {  
       		    timer_button.stop();
	        }
        }  
    } 

    Rectangle {  
        id: browser2Button  
        anchors.right: parent.right  
        anchors.bottom: parent.bottom  
        color: "gray"  

        width: parent.width/4  
        height: 80

        Text {  
            anchors.centerIn: parent  
            text: "Browser2"  
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
            PropertyChanges { target: browser1Button; color: "blue"; }  
            PropertyChanges { target: dialLoader; source: "browser1.qml"; }  
        },

        State {  
            name: "browser2"  
            PropertyChanges { target: browser2Button; color: "blue"; }  
            PropertyChanges { target: dialLoader; source: "browser2.qml"; }  
        }  
    ]  
}  
