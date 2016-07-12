import QtQuick 2.0  

Rectangle {  
		id: root  
		width: 1024  
		height: 600 
		property int testcount: 0
		property int category: 0
		property int checkloaded: 0
		property int swapnumber: 200
		property int speed: 0  


	SequentialAnimation {  
			running: true  
			loops: Animation.Infinite  

			NumberAnimation { target: root; property: "speed"; to: 145; easing.type: Easing.InOutQuad; duration: 4000; }  
		 	NumberAnimation { target: root; property: "speed"; to: 10; easing.type: Easing.InOutQuad; duration: 2000; }  
	} 

	Text{
		id: rate   
		text:"Total Time"; 
		color: "red"
		font.pointSize:36;  
	}

	Loader {  
		id: dialLoader  
		anchors.left: parent.left  
		anchors.right: parent.right  
		anchors.top: parent.top  
		anchors.bottom: page1Button.top  
		
		onLoaded: {  
			binder.target = dialLoader.item; 
			checkloaded=1;
			
			//console.log("swapnumber "+ swapnumber)
			swappage.myPrty=swapnumber;

			if(swapnumber==0){
				swappage.myPrty=swapnumber;
				swapnumber=200;
				category++;
			}
			swapnumber--;
		}  
	} 

	Binding {  
		id: binder  
		property: "speed"  
		value: speed  
	}  

	Rectangle {  
		id: page1Button  
		anchors.left: parent.left  
		anchors.bottom: parent.bottom  
		color: "gray"  
		width: parent.width/3  
		height: 100  

		Text {  
			anchors.centerIn: parent  	
			font.pointSize:36;  
			text: "page1"  
		}  

		MouseArea {  
			anchors.fill: parent  
			onClicked: {
				root.state = "textpage1";  
			}
		}  
	}  

	Rectangle {  
		id: page2Button  

		anchors.left: page1Button.right 
		anchors.bottom: parent.bottom  

		color: "gray"  

		width: parent.width/3  
		height: 100  

		Text {  
			anchors.centerIn: parent  
			font.pointSize:36;  
			text: "page2"  
		}  

		MouseArea {  
			anchors.fill: parent  
			onClicked: {
				root.state = "svgpage2";  
				rate.text = swappage.totaltime
			}
		}  
	}  
	
	Rectangle {  
		id: page3Button  

		anchors.right: parent.right  
		anchors.bottom: parent.bottom  

		color: "gray"  

		width: parent.width/3  
		height: 100  

		Text {  
			anchors.centerIn: parent  
			font.pointSize:36;  
			text: "page3"  
		}  

		MouseArea {  
			anchors.fill: parent  
			onClicked: {
				root.state = "pngpage3";  
				rate.text = swappage.totaltime
			}
		}  
	} 

	state: "textpage1"  

	states: [  
		State {  
			name: "pngpage1"  
			PropertyChanges { target: page1Button; color: "green"; }  
			PropertyChanges { target: dialLoader; source: "item_png1.qml"; }  
		},
		
		State {  
			name: "pngpage2"  
		  	PropertyChanges { target: page2Button; color: "green"; }  
	  		PropertyChanges { target: dialLoader; source: "item_png2.qml"; }  
		},	
		
		State {  
			name: "pngpage3"  
		  	PropertyChanges { target: page3Button; color: "green"; }  
	  		PropertyChanges { target: dialLoader; source: "item_png3.qml"; }  
		},   

	 	State {  
			name: "svgpage1"  
		  	PropertyChanges { target: page1Button; color: "green"; }  
	  		PropertyChanges { target: dialLoader; source: "item_svg1.qml"; }  
		},
	 	
		State {  
			name: "svgpage2"  
		  	PropertyChanges { target: page2Button; color: "green"; }  
	  		PropertyChanges { target: dialLoader; source: "item_svg2.qml"; }  
		},
	 	
		State {  
			name: "svgpage3"  
		  	PropertyChanges { target: page3Button; color: "green"; }  
	  		PropertyChanges { target: dialLoader; source: "item_svg3.qml"; }  
		},

		State {  
			name: "textpage1"  
		  	PropertyChanges { target: page1Button; color: "green"; }  
	  		PropertyChanges { target: dialLoader; source: "item_text1.qml"; }  
		}, 	
		
		State {  
			name: "textpage2"  
		  	PropertyChanges { target: page2Button; color: "green"; }  
	  		PropertyChanges { target: dialLoader; source: "item_text2.qml"; }  
		},  	
		
		State {  
			name: "textpage3"  
		  	PropertyChanges { target: page3Button; color: "green"; }  
	  		PropertyChanges { target: dialLoader; source: "item_text3.qml"; }  
		}    	
	] 

	Timer
	{
		interval:10
		running: true  
		repeat: true   
		onTriggered:
		{
			testcount++;
			if(checkloaded==1){
				if((testcount%3)==0){
					checkloaded=0;
					if(category==0){
						root.state = "textpage1";  
					}else if(category==1){
						root.state = "svgpage1";  
					}else if(category==2){
						root.state = "pngpage1";  
					}
				}else if((testcount%3)==1){
					checkloaded=0;	
					if(category==0){
						root.state = "textpage2";  
					}else if(category==1){
						root.state = "svgpage2";  
					}else if(category==2){
						root.state = "pngpage2";  
					}
				}else if((testcount%3)==2){
					checkloaded=0;	
					if(category==0){
						root.state = "textpage3";  
					}else if(category==1){
						root.state = "svgpage3";  
					}else if(category==2){
						root.state = "pngpage3";  
					}
				}
				
				if((category==3)&&(testcount==601)){
					swappage.myPrty=-1;
				}

			}
		}
	}

}  
