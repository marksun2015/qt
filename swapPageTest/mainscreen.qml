import QtQuick 2.0  

Rectangle {  
		id: root  
		width: 1024  
		height: 600  
		property int speed: 0  
		SequentialAnimation {  
			running: true  
			loops: Animation.Infinite  

			NumberAnimation { target: root; property: "speed"; to: 145; easing.type: Easing.InOutQuad; duration: 4000; }  
		 	NumberAnimation { target: root; property: "speed"; to: 10; easing.type: Easing.InOutQuad; duration: 2000; }  
		}  
	 
	Loader {  
		id: dialLoader  
		anchors.left: parent.left  
		anchors.right: parent.right  
		anchors.top: parent.top  
		anchors.bottom: pngpageButton.top  

		onLoaded: {  
			binder.target = dialLoader.item;  
		}  
	}  
	Binding {  
		id: binder  
		property: "speed"  
		value: speed  
	}  

	MouseArea {  
			anchors.fill: parent  
			onClicked: {
				//! console.log("-------");
				//! console.log(mouse.x);
				if(mouse.x == 0){
					root.state = "pngpage";  
				}else if(mouse.x == 1){
					root.state = "svgpage";  
				}else{
					root.state = "textpage";  
				}
			}
	}  

	Rectangle {  
		id: pngpageButton  
		anchors.left: parent.left  
		anchors.bottom: parent.bottom  
		color: "gray"  
		width: parent.width/3  
		height: 100  

		Text {  
			anchors.centerIn: parent  
			text: "load png page"  
		}  

		MouseArea {  
			anchors.fill: parent  
			onClicked: {
				root.state = "pngpage";  
				//!console.log(mouse.x);
				//!console.log(mouse.y);
			}
		}  
	}  

	Rectangle {  
		id: svgpageButton  

		anchors.left: pngpageButton.right 
		anchors.bottom: parent.bottom  

		color: "gray"  

		width: parent.width/3  
		height: 100  

		Text {  
			anchors.centerIn: parent  
			text: "load svg page"  
		}  

		MouseArea {  
			anchors.fill: parent  
			onClicked: {
				root.state = "svgpage";  
				//!console.log(mouse.x);
				//!console.log(mouse.y);
			}
		}  
	}  
	
	Rectangle {  
		id: textpageButton  

		anchors.right: parent.right  
		anchors.bottom: parent.bottom  

		color: "gray"  

		width: parent.width/3  
		height: 100  

		Text {  
			anchors.centerIn: parent  
			text: "load text page"  
		}  

		MouseArea {  
			anchors.fill: parent  
			onClicked: {
				root.state = "textpage";  
				//!console.log(mouse.x);
				//!console.log(mouse.y);
			}
		}  
	} 

	state: "pngpage"  

	states: [  
		State {  
			name: "pngpage"  
			PropertyChanges { target: pngpageButton; color: "green"; }  
			PropertyChanges { target: dialLoader; source: "item_png.qml"; }  
		},

	 	State {  
			name: "svgpage"  
		  	PropertyChanges { target: svgpageButton; color: "green"; }  
	  		PropertyChanges { target: dialLoader; source: "item_svg.qml"; }  
		},

		State {  
			name: "textpage"  
		  	PropertyChanges { target: textpageButton; color: "green"; }  
	  		PropertyChanges { target: dialLoader; source: "item_text.qml"; }  
		}    
	]  
}  
