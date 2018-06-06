import QtQuick 2.0
import QtQuick.Window 2.0
import QtLocation 5.6
import QtPositioning 5.6

Rectangle {
    width: Screen.width
    height: Screen.height
    visible: true

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    property variant currentPosition: QtPositioning.coordinate( 50.9793, 11.0282)

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: currentPosition
        zoomLevel: 18

        MapQuickItem {
            id: marker
            anchorPoint.x: image.width/2
            anchorPoint.y: image.height
            coordinate: currentPosition

            sourceItem: Image {
                id: image
                source: "qrc:/mm_20_red.png"
                width: 30
                height: 30
            }
        }
    }

    PositionSource {
        id: positionSource
        active: true
        updateInterval: 5000 // 5 sec

        onPositionChanged:  {
            currentPosition = positionSource.position.coordinate
            map.center = currentPosition
            marker.coordinate = currentPosition
        }
    }

}
