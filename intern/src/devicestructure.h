#ifndef DEVICESTRUCTURE_H
#define DEVICESTRUCTURE_H

#include <QString>
#include <QHostAddress>
#include <QtXml>

class CDeviceStructure
{

private:

    enum EDevices
    {
        SENSOR,
        LAMP,
        RADIATOR
    };

public:
    struct Device
    {
      QString       m_Name;
      QHostAddress  m_IpAddress;
      QString       m_MacAddress;
      EDevices      m_DeviceType;
    };

public:
    CDeviceStructure();
    bool save();
    bool load();
    bool deleteDevice(QString _Name);
    bool addDevices(QString       _Name,
                    QHostAddress  _IpAddress,
                    QString       _MacAddress,
                    EDevices      _DeviceType);


    QList<Device> returnDevices();
    QList<Device> retrievElements(QDomElement root, QString tag);


private:
    QList<Device> m_Devices;

    QString m_FileName              = "devicelist.xml";

    QString m_XmlNameString         = "Name";
    QString m_XmlIpAdressString     = "IpAddress";
    QString m_XmlMacAddressString   = "MacAddress";
    QString m_XmlDeviceTypeString   = "DeviceType";




};

#endif // DEVICESTRUCTURE_H
