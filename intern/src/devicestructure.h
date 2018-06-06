#ifndef DEVICESTRUCTURE_H
#define DEVICESTRUCTURE_H

#include <QString>
#include <QHostAddress>
#include <QtXML>

class CDeviceStructure
{

private:

    ///
    /// \brief The EDevices enum
    /// create for every device own class with individual functions
    ///
    enum EDevices
    {
        PHILIPLSCLOLORLAMP,
        PHILIPLSLUXLAMP,
        TEMPERATURESENSOR,
        HUMIDITYSENSOR
    };

public:
    struct Device
    {
      QString       m_Name;
      QHostAddress  m_IpAddress;
      QString       m_MacAddress;
      EDevices      m_DeviceType;
      int           m_DeviceNumber;
    };

public:
    CDeviceStructure();
    bool save();
    bool load();
    bool deleteDevice(QString _Name);
    bool addDevices(QString       _Name,
                    QHostAddress  _IpAddress,
                    QString       _MacAddress,
                    EDevices      _DeviceType,
                    int           _DeviceNumber);


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
