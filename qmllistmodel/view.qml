import QtQuick 2.0

ListView {
    width: 300; height: 300
    model: myModel
    delegate: Rectangle {
        height: 50
        width: 300
        color: model.modelData.color
        Text 
		{ 
			text: name 
			font.pointSize: 24
		}
    }
}
