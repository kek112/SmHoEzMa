import QtQuick 2.9
import QtQuick.Controls 1.2
import QtLocation 5.6
import QtPositioning 5.6



//width: 50
//height: 200
//visible: true

Rectangle {

    width: 50
    height: 200
    visible: true


    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: map

        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate( 50.9793, 11.0282)
        zoomLevel: 18

        MapQuickItem {
            id: marker
            anchorPoint.x: image.width/2
            anchorPoint.y: image.height
            coordinate: QtPositioning.coordinate( 50.9793, 11.0282)

            sourceItem: Image {
                id: image
                source: "qrc:/marker.png"
                width: 20
                height: 30
            }
        }

        gesture.enabled: false

        PositionSource {
            id: positionSource
            active: true
            Component.onCompleted:  {
                var currentPosition = positionSource.position.coordinate;
                map.center = currentPosition;
                marker.coordinate = currentPosition;
            }
        }

        //Set extra area for gestures (manuel machen)
        function setGestureSize() {
            console.log("Height: " ,map.gesture.height);
            console.log("Width: " ,map.gesture.width);
            map.gesture.height = 200;
            map.gesture.width = 200;
            console.log("Height: " ,map.gesture.height);
            console.log("Width: " ,map.gesture.width);
        }

    }
}

//    Rectangle {
//        width: parent.width
//        height: parent.height/2
//        visible: true
//        anchors.bottom: parent.bottom

//        Button {
//            text: "Position aktualisieren"
//            anchors.top: parent.top
//            anchors.left: parent.left
//            anchors.topMargin: 5
//            anchors.leftMargin: 5
//            MouseArea {
//                anchors.fill: parent
//                onClicked: {
//                    var currentPosition = positionSource.position.coordinate;
//                    map.center = currentPosition;
//                    marker.coordinate = currentPosition;
//                    parent.text = 'Aktualisiert!';
//                }
//            }
//        }

//        Button {
//            text: "Position speichern"
//            anchors.top: parent.top
//            anchors.left: parent.left
//            anchors.topMargin: 90
//            anchors.leftMargin: 5
//            MouseArea {
//                anchors.fill: parent
//                onClicked: {
//                    parent.text = 'Gespeichert!'
//                }
//            }
//        }


//    }

