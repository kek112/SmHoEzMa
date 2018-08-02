import QtQuick 2.0
import QtQuick.Layouts 1.3

Item {
    property string title;
    ColumnLayout {
        RowLayout {
            Text {
                text: title
            }
            Item {
                Image {
                    id: arrow
                    source: "qrc:/arrowDown"
                }
            }
        }
        Text {
            text: "testText"
        }
    }
}
