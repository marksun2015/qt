import QtQuick 2.0
import QtMultimedia 5.0

Rectangle {
    width: 1024
    height: 600
    color: "white"

    Row{
        spacing: 5; // a simple layout do avoid overlapping

    Repeater {
        model: 5; // just define the number you want, can be a variable too
		delegate:Column {
        spacing: 5; // a simple layout do avoid overlapping

        Repeater {
            model: 14; // just define the number you want, can be a variable too
            //delegate: Rectangle {
            //    width: 200;
            //    height: 30;
                //color: "#6644FF";
                //border { width: 1; color: "black" }
				Text{
					text:"am335x";
					font.family:"Arial;"
					font.pointSize:20;
					color: "gray"
				}
            //}
        }
	}

    }
   } // end row

}
