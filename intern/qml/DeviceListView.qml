import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    ColumnLayout {
        anchors.top: parent.top
        id: mainLayout
        AccordionElement {

        }

    }

    RowLayout {
        anchors.bottom: parent.bottom
        Layout.alignment: Qt.AlignCenter
        Button {
            id: addButton
            Image {
                source: "qrc:/add"
                anchors.fill: parent
            }
        }
        Button {
            id: removeButton
            Image {
                source: "qrc:/remove"
                anchors.fill: parent
            }
        }
    }

    function addDevice () {
        Qt.createQmlObject(AccordionElement, mainLayout)
    }
}
