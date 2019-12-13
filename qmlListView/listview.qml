import QtQuick 2.0

ListView {
    width: 380; height: 200

    Component {
        id: contactsDelegate
        Rectangle {
            id: wrapper
            width: 380
            height: contactInfo.height
            color: ListView.isCurrentItem ? "black" : "red"
            Text {
                id: contactInfo
				font.pointSize: 24
                text: name + ": " + number
                color: wrapper.ListView.isCurrentItem ? "red" : "black"
            }
        }
    }

    model: ContactModel {}
    delegate: contactsDelegate
    focus: true
}
