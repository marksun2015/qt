// warning.qml
import QtQuick.Window 2.1
import QtQuick 2.0

Rectangle {
    id: r_view
    width: Screen.width
    height: Screen.height
    color: "#d3d3d3"
    property string message: "Please upgrade the EasyBuilder Pro to the \nminimum required version: V6.05.01.512"

    Rectangle {
        width: Screen.width
        height: 100
        color: "Red"
        Text{
            text: "Warning"
            font{
                pixelSize: 34
                family: "Droid Sans"
            }
            color: "black"
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    Image {
	id: i_view
	source:"free-labels.jpeg"
	anchors.horizontalCenter: parent.horizontalCenter
	anchors.verticalCenter: parent.verticalCenter

        width: 700
        height: 200
 
    	Text{
            text: r_view.message
            font{
                pixelSize: 34
                family: "Droid Sans"
            }
            color: "black"
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
