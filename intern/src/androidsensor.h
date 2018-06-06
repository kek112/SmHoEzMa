#ifndef ANDROIDSENSOR_H
#define ANDROIDSENSOR_H

#include <QDebug>
#include <QNmeaPositionInfoSource>

class CAndroidSensor : QObject
{
    Q_OBJECT
public:
    CAndroidSensor(QObject *parent = 0);

private slots:
    void positionUpdated(const QGeoPositionInfo &info);
    void setGPSLocation(QGeoPositionInfo geoPositionInfo);

private:
    QGeoPositionInfoSource* locationInfo_;
};

#endif // ANDROIDSENSOR_H
