#include "mapthread.h"

CMapThread::CMapThread(CDeviceStructure *_pDevices, QObject *parent)
    : QObject(parent)
    , m_pDevices(_pDevices)
{

}

void CMapThread::checkGPS()
{
    forever
    {
        QGeoCoordinate coordinate = m_GPS.getGPSLocation();

        int deviceNumber = 0;

        for(auto device : m_pDevices->returnDevices())
        {
            if(device.m_Active && device.m_Coordinate.distanceTo(coordinate) < 100)
            {
                emit reachedHome(deviceNumber);
            }
            deviceNumber++;
        }
    }
}
