#include "deviceview.h"

CDeviceView::CDeviceView(CDeviceStructure::Device _device, QWidget *parent)
    : QWidget(parent)
    , m_Device(_device)
{
    switch(m_Device.m_DeviceType)
    {
    case CDeviceStructure::PHILIPLSCLOLORLAMP:
    {

        break;
    }
    case CDeviceStructure::PHILIPLSLUXLAMP:
    {

        break;
    }
    case CDeviceStructure::TEMPERATURESENSOR:
    {

        break;
    }
    case CDeviceStructure::HUMIDITYSENSOR:
    {

        break;
    }
    }
}

void CDeviceView::UpdateDevice(CDeviceStructure::Device _device)
{

}
