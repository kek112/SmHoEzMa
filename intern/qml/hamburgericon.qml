import QtQuick 2.2

Rectangle {
    width: 48
    height: 48
    color: "#9c27b0"

    MouseArea {
        anchors.fill: parent
        onClicked: menuBackIcon.state = menuBackIcon.state === "menu" ? "back" : "menu"
    }

    MenuBackIcon {
        id: menuBackIcon
        anchors.centerIn: parent
    }
}
