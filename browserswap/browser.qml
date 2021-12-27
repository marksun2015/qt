/******************************************************************************
 **
 ** Copyright (C) 2014 - 2020 Weintek, Inc. All rights reserved.
 ** Contact: http://www.weintek.com
 **
 ** This file is part of the Weintek Browser.
 **
 ** $BEGIN_LICENSE:COMM$
 **
 ** Commercial License Usage
 **
 ** Licensees holding a valid Commercial License for this product from
 ** Weintek, Inc. may use this file in accordance with the
 ** Commercial License Agreement provided with the Software.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING
 ** THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 ** PURPOSE.
 **
 ** $END_LICENSE$
 **
 ******************************************************************************/

import QtQuick 2.0
import QtQuick.Layouts 1.0

import Weintek.Browser 1.0

Rectangle {
    width: 1024
    height: 768
    property int loading: 0

    ColumnLayout{
        spacing: 2

        Rectangle {
            Layout.alignment: Qt.AlignBottom
            Layout.fillHeight: true
            color: "pink"
            Layout.preferredWidth: 100
            Layout.preferredHeight: 40

            Text {
                anchors.fill:parent
                id: show
                font.pointSize: 10
                color: "steelblue"
                text:qsTr("Show")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("create0")
                    browser.url = "https://www.google.com"
                    browser.show()
                    browser.setGeometry(120,10,800,700)
                }
            }
        }

        Rectangle {
            Layout.alignment: Qt.AlignBottom
            Layout.fillHeight: true
            color: "pink"
            Layout.preferredWidth: 100
            Layout.preferredHeight: 40

            Text {
                anchors.fill:parent
                id: hide
                font.pointSize: 10
                color: "steelblue"
                text:qsTr("Hide")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("hide")
                    browser.hide()
                }
            }
        }

        Rectangle {
            Layout.alignment: Qt.AlignCenter
            color: "darkslategray"
            Layout.preferredWidth: 100
            Layout.preferredHeight: 40

            Text {
                anchors.fill:parent
                id: toolbarshow
                font.pointSize: 10
                color: "cyan"
                text:qsTr("BarShow ")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    browser.toolbar=1
                }
             }
        }

        Rectangle {
            Layout.alignment: Qt.AlignCenter
            color: "darkslategray"
            Layout.preferredWidth: 100
            Layout.preferredHeight: 40

            Text {
                anchors.fill:parent
                id: toolbarhide
                font.pointSize: 10
                color: "cyan"
                text:qsTr("BarHide")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    browser.toolbar=0
                }
             }
        }

        Rectangle {
            Layout.alignment: Qt.AlignCenter
            color: "red"
            Layout.preferredWidth: 100
            Layout.preferredHeight: 40

            Text {
                anchors.fill:parent
                id: url0
                font.pointSize: 10
                color: "black"
                text:qsTr("Google")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("goto https://google.com")
                    browser.url = "https://google.com"
                }
             }
        }

        Rectangle {
            Layout.alignment: Qt.AlignRight
            color: "yellow"
            Layout.preferredWidth: 100
            Layout.preferredHeight: 40

            Text {
                anchors.fill:parent
                id: url1
                font.pointSize: 10
                color: "steelblue"
                text:qsTr("Reload")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("reload page")
                    browser.reload()
                }
            }
        }

        Rectangle {
            Layout.alignment: Qt.AlignBottom
            Layout.fillHeight: true
            color: "yellow"
            Layout.preferredWidth: 100
            Layout.preferredHeight: 40

            Text {
                anchors.fill:parent
                id: back0
                font.pointSize: 10
                color: "steelblue"
                text:qsTr("Back")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("go back")
                    browser.goBack()
                }
            }
        }
	
        Rectangle {
            Layout.alignment: Qt.AlignBottom
            Layout.fillHeight: true
            color: "yellow"
            Layout.preferredWidth: 100
            Layout.preferredHeight: 40

            Text {
                anchors.fill:parent
                id: forward0
                font.pointSize: 10
                color: "steelblue"
                text:qsTr("Forward")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("go forward")
                    browser.goForward()
                }
            }
        }

        Rectangle {
            Layout.alignment: Qt.AlignBottom
            Layout.fillHeight: true
            color: "yellow"
            Layout.preferredWidth: 100
            Layout.preferredHeight: 40

            Text {
                anchors.fill:parent
                id: zoomin
                font.pointSize: 10
                color: "steelblue"
                text:qsTr("zoomin")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("set zoom in")
                    browser.setZoomIn()
                }
            }
        }

        Rectangle {
            Layout.alignment: Qt.AlignBottom
            Layout.fillHeight: true
            color: "yellow"
            Layout.preferredWidth: 100
            Layout.preferredHeight: 40

            Text {
                anchors.fill:parent
                id: zoomout
                font.pointSize: 10
                color: "steelblue"
                text:qsTr("zoomout")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("set zoom out")
                    browser.setZoomOut()
                }
            }
        }

        Rectangle {
            Layout.alignment: Qt.AlignBottom
            Layout.fillHeight: true
            color: "gray"
            Layout.preferredWidth: 100
            Layout.preferredHeight: 40

            Text {
                anchors.fill:parent
                id: clear
                font.pointSize: 10
                color: "white"
                text:qsTr("Clear")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("clear record")
                    browser.clearCache()
                    browser.clearCookie()
                }
            }
        }

        Rectangle {
            Layout.alignment: Qt.AlignBottom
            Layout.fillHeight: true
            color: "gray"
            Layout.preferredWidth: 100
            Layout.preferredHeight: 40

            Text {
                anchors.fill:parent
                id: inspectorOn
                font.pointSize: 10
                color: "white"
                text:qsTr("Inspector on")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("clear record")
                    browser.setInspector(1);
                }
            }
        }

        Rectangle {
            Layout.alignment: Qt.AlignBottom
            Layout.fillHeight: true
            color: "gray"
            Layout.preferredWidth: 100
            Layout.preferredHeight: 40

            Text {
                anchors.fill:parent
                id: inspectorOff
                font.pointSize: 10
                color: "white"
                text:qsTr("Inspector off")
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("clear record")
                    browser.setInspector(0);
                }
            }
        }
    }

    Timer {
            id: timer_button;
            interval: 500;//设置定时器定时时间为500ms,默认1000ms
            repeat: false //是否重复定时,默认为false
            running: false //是否开启定时，默认是false，当为true的时候，进入此界面就开始定时
            triggeredOnStart: true // 是否开启定时就触发onTriggered，一些特殊用户可以用来设置初始值。
            onTriggered: {
                    console.log("loadingStatus")
                    console.log(loadingStatus)
            }
    }

    BrowserView {
        id: browser
        x:80
        y:10
        width:800
        height:700
    }

    Component.onCompleted: {
        console.log("onCompleted")
        browser.url = "https://www.webkitgtk.org"
        browser.home = "https://www.mobile01.com"
        browser.show()
    }
}
