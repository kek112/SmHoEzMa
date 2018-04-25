#ifndef ANDROIDSENSOR_H
#define ANDROIDSENSOR_H

#include <QDebug>
#include <QNmeaPositionInfoSource>

class AndroidSensor : QObject
{
    Q_OBJECT
public:
    AndroidSensor(QObject *parent = 0)
        : QObject(parent)
    {
//        qDebug()<<QGeoPositionInfoSource::availableSources();
//        QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
//        if (source) {
//            connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
//                    this, SLOT(positionUpdated(QGeoPositionInfo)));
//            source->startUpdates();
//        }

        // obtain the location data source
        locationInfo_ = QGeoPositionInfoSource::createDefaultSource(this);

        // select positioning method
        locationInfo_->setPreferredPositioningMethods(QGeoPositionInfoSource::AllPositioningMethods);

        // when the position has changed the setGPSLocation slot is called
        connect(locationInfo_, SIGNAL(positionUpdated(QGeoPositionInfo)),
                this, SLOT(setGPSLocation(QGeoPositionInfo)));

        // start listening for position updates
        locationInfo_->startUpdates();
    }

private slots:
    void positionUpdated(const QGeoPositionInfo &info)
    {
        qDebug() << "Position updated:" << info;
    }
    void setGPSLocation(QGeoPositionInfo geoPositionInfo)
    {
        QString text="Location=unknown";

            if (geoPositionInfo.isValid())
            {
                // get the current location coordinates
                QGeoCoordinate geoCoordinate = geoPositionInfo.coordinate();

                // transform coordinates to lat/lon
                qreal latitude = geoCoordinate.latitude();
                qreal longitude = geoCoordinate.longitude();

                text=QString("Latitude=%1\nLongitude=%2")
                        .arg(latitude,0,'g',8)
                        .arg(longitude,0,'g',8);
            }
            qDebug()<<text;

    }

private:
    QGeoPositionInfoSource* locationInfo_;
};

#endif // ANDROIDSENSOR_H
