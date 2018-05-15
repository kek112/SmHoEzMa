#ifndef DEVICESTRUCTURE_H
#define DEVICESTRUCTURE_H

#include <QString>
#include <QHostAddress>
class CDeviceStructure
{
    Q_OBJECT
public:
    CDeviceStructure();
    void save();
    void load();
    void deleteDevice();
    QList<Devices> returnDevices();
    void addDevices();


private:
    QList<Device> m_Devices ;



private:
    struct Device
    {
      QString       m_Name;
      QHostAddress  m_IpAddress;
      QString       m_MacAddress;
      EDevices      m_DeviceType;
    };

    enum EDevices
    {
        SENSOR,
        LAMP,
        RADIATOR
    };
};

#endif // DEVICESTRUCTURE_H
