import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3

Item {
    Material.theme: Material.Dark
    Material.accent: Material.Blue

    ColumnLayout {
        id: mainLayout
        anchors.fill: parent

        Rectangle {
            RowLayout {

                HamburgerIcon {
                    id: menuButton
                }

                Text {
                    text: "SmHoEzMa"
                }
            }
        }

        StackLayout {
            id: stack
            //insert Diffrent Views
            DeviceListView {
            }
        }

    }
}
