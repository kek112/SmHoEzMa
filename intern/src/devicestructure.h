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
    void addDevices();


    QList<Devices> returnDevices();
    QList<Devices> retrievElements(QDomElement root, QString tag);


private:
    QList<Device> m_Devices;

    QString m_FileName              = "devicelist.xml";

    QString m_XmlNameString         = "Name";
    QString m_XmlIpAdressString     = "IpAddress";
    QString m_XmlMacAddressString   = "MacAddress";
    QString m_XmlDeviceTypeString   = "DeviceType";


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
