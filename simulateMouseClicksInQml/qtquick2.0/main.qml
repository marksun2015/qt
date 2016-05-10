import QtQuick 2.0

Rectangle {
	width: 360
	height: 360
	Text {
		id: text1
		text: qsTr("This text is placed at the click coordinates")
	}

   	MouseArea {
		id: mousearea1
		anchors.fill: parent
		onClicked: {
			console.log("click at " + mouse.x + ", " + mouse.y);
			text1.x = mouse.x;
			text1.y = mouse.y;
		}
	}
}
