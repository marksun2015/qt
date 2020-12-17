// warning.qml
import QtQuick.Window 2.1
import QtQuick 2.0

Rectangle {
    id: r_view
    width: Screen.width
    height: Screen.height
    //color: "#d3d3d3"
    color: "gray"
    property string message: "Please upgrade the EasyBuilder Pro to the \nminimum required version: V6.05.01.512"


    Rectangle {
        x: Screen.width/2 - 350 + 10
        y: Screen.height/2 - 100 + 10
        width: 700
        height: 200
        color: "black"
        radius: 10
    }

    Rectangle {
        x: Screen.width/2 - 350
	    y: Screen.height/2 - 100
        width: 700
        height: 200
        color: "darkblue"
        //color: "midnightblue"
        //color: "cornflowerblue"
        //border.color: "red"
        //border.width: 2
        radius: 10
        Text{
            text: r_view.message
            color: "whitesmoke"
            //color: "snow"
            //color: "antiquewhite"
            font{
                pixelSize: 34
                family: "Droid Sans"
            }
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
 
}
