import QtQuick 2.0
import QtQuick.Window 2.0
import QtLocation 5.6
import QtPositioning 5.6

Rectangle {
    width: 200
    height: 200
    visible: true

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    property variant locationErfurt: QtPositioning.coordinate( 50.9793, 11.0282)

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: locationErfurt
        zoomLevel: 14
    }

    PositionSource {
        id: positionSource
        active: true
        updateInterval: 5000 // 5 sec
        onPositionChanged:  {
            var currentPosition = positionSource.position.coordinate
            map.center = currentPosition
        }
    }
}
