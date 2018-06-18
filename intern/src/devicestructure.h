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
    /// this will decide which options are displayed on the view and which classes are to be created
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
    bool deleteDevice(int _Index);
    bool deleteDevice(QString _Name);
    bool addDevices(QString       _Name,
                    QHostAddress  _IpAddress,
                    QString       _MacAddress,
                    EDevices      _DeviceType,
                    int           _DeviceNumber);


    QList<Device> returnDevices();
    QList<Device> retrieveElements(QDomElement root, QString tag);


private:
    QList<Device> m_Devices;

    QString m_FileName              = "devicelist.xml";

    QString m_XmlNameString         = "Name";
    QString m_XmlIpAdressString     = "IpAddress";
    QString m_XmlMacAddressString   = "MacAddress";
    QString m_XmlDeviceTypeString   = "DeviceType";
    QString m_XmlDeviceNumber       = "DeviceNumber";




};

#endif // DEVICESTRUCTURE_H
