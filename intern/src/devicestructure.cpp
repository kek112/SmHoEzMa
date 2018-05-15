#include "devicestructure.h"

#include <QStandardPaths>
#include <QtXML>

///
/// \brief CDeviceStructure::CDeviceStructure
///
CDeviceStructure::CDeviceStructure()
{
    load();
}


///
/// \brief CDeviceStructure::save
/// \return
///
bool CDeviceStructure::save()
{

    return false;
}

///
/// \brief CDeviceStructure::load
/// load all devices from xml into struct
/// best when called first so u have a device list :)
/// check if xml exists
/// return
/// \return
///
bool CDeviceStructure::load()
{
    QDomDocument document;
    QFile file = QStandardPaths::StandardLocation(QStandardPaths::AppConfigLocation)[0] + m_FileName;

    // Open a file for reading
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the file for reading.";
        return -1;
    }
    else
    {
        // loading
        if(!document.setContent(&file))
        {
            qDebug() << "Failed to load the file for reading.";
            return -1;
        }
        file.close();
    }

    // Getting root element
    QDomElement root = document.firstChildElement();

    // retrievelements(QDomElement root, QString tag, QString att)
    m_Devices = retrievElements(root, "Devices");

}

///
/// \brief CDeviceStructure::returnDevices
/// returns all devices which are currently saved in the structure
/// \return
/// returns all devices which are currently saved in the structure :=)
///
QList<CDeviceStructure::Device> CDeviceStructure::returnDevices()
{
    return m_Devices;
}

///
/// \brief CDeviceStructure::addDevices
/// add one device to your list
/// create new struct and add it to list
/// checks if the name is already taken :)
/// \return
/// after check has failed it will return false otherwise
/// new struct is added and true will be returned
///
bool CDeviceStructure::addDevices(  QString       _Name,
                                    QHostAddress  _IpAddress,
                                    QString       _MacAddress,
                                    EDevices      _DeviceType)
{
    Device device;

    foreach (Device tempdevice, m_Devices)
    {
        if(tempdevice.m_Name == _Name)
        {
            return false;
        }
    }

    device.m_Name       = _Name;
    device.m_IpAddress  = _IpAddress;
    device.m_MacAddress = _MacAddress;
    device.m_DeviceType = _DeviceType;

    m_Devices.append(device);
    return true;
}

///
/// \brief CDeviceStructure::deleteDevice
/// delete one specific device with the name
/// \return
/// will return true if name exists in lsist othgerwise false :)
///
bool CDeviceStructure::deleteDevice(QString _Name)
{
    foreach (Device tempdevice, m_Devices)
    {
        if(tempdevice.m_Name == _Name)
        {
            m_Devices.removeAt(m_Devices.indexOf(tempdevice));
            return true
        }
    }
    return false;
}

///
/// \brief retrievElements
/// runs through all nodes under the tag and puts them into the device list
/// \param root
/// needs root element from where to start
/// \param tag
/// specify which node is important
/// \return
/// returns list created from the nodes
QList<CDeviceStructure::Device> CDeviceStructure::retrievElements(QDomElement root, QString tag)
{

    QList<Device> devicelist;
    QDomNodeList nodes = root.elementsByTagName(tag);

    //qDebug() << "# nodes = " << nodes.count();
    for(int i = 0; i < nodes.count(); i++)
    {
        QDomNode elm = nodes.at(i);
        if(elm.isElement())
        {
            QDomElement e = elm.toElement();

            Device device;

            device.m_Name           = e.attribute(m_XmlNameString);
            device.m_IpAddress      = e.attribute(m_XmlIpAdressString);
            device.m_MacAddress     = e.attribute(m_XmlMacAddressString);
            device.m_DeviceType     = e.attribute(m_XmlDeviceTypeString);

            devicelist.append(device);
        }
    }
    return devicelist;
}