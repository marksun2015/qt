import QtQuick 2.0
import CustomImage 1.0

Item {
	 visible: true

	 width:1024 
	 height:600 

	 Rectangle
	 {
		id: image
		color: "transparent"
		border.color: "red"

		anchors
		{
			margins: 20
			 centerIn: parent
			 fill: parent
		}

		MyImage
		{
			anchors
			{
				centerIn: parent
			}
		}
	 }
}
