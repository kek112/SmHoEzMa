#include "deviceview.h"
#include "humiditysensor.h"
#include "tempereratursensor.h"

CDeviceView::CDeviceView(CDeviceStructure::Device _device, QWidget *parent)
    : QWidget(parent)
    , m_Device(_device)
{
    switch(m_Device.m_DeviceType)
    {
    case CDeviceStructure::PHILIPLSCLOLORLAMP:
    {
        m_pBrightnessDescriptionLabel   = new QLabel("Brightness", this);
        m_pSaturationDescriptionLabel   = new QLabel("Saturation", this);
        m_pColorDescriptionLabel        = new QLabel("Color", this);
        m_pOnOffDescriptionLabel        = new QLabel("Active", this);


        m_pBrightnessSlider = new QSlider(Qt::Horizontal, this);
        m_pSaturationSlider = new QSlider(Qt::Horizontal, this);

        CSwitchWidget* SwitchWidget = new CSwitchWidget(this);
        SwitchWidget->setMinimumHeight(64);
        SwitchWidget->setMinimumWidth(128);

        m_pMainLayout = new QGridLayout();

        m_pMainLayout->addWidget(m_pBrightnessDescriptionLabel, 0,0);
        m_pMainLayout->addWidget(m_pSaturationDescriptionLabel, 1,0);
        m_pMainLayout->addWidget(m_pColorDescriptionLabel,      2,0);
        m_pMainLayout->addWidget(m_pOnOffDescriptionLabel,      3,0);


        m_pMainLayout->addWidget(m_pBrightnessSlider,   0,1);
        m_pMainLayout->addWidget(m_pSaturationSlider,   1,1);
        //colorPicker
        m_pMainLayout->addWidget(SwitchWidget,          3,1, Qt::AlignRight);

        break;
    }
    case CDeviceStructure::PHILIPLSLUXLAMP:
    {
        m_pBrightnessDescriptionLabel   = new QLabel("Brightness", this);
        m_pSaturationDescriptionLabel   = new QLabel("Saturation", this);
        m_pOnOffDescriptionLabel        = new QLabel("Active", this);


        m_pBrightnessSlider = new QSlider(Qt::Horizontal, this);
        m_pSaturationSlider = new QSlider(Qt::Horizontal, this);

        CSwitchWidget* SwitchWidget = new CSwitchWidget(this);
        SwitchWidget->setMinimumHeight(64);
        SwitchWidget->setMinimumWidth(128);

        m_pMainLayout = new QGridLayout();

        m_pMainLayout->addWidget(m_pBrightnessDescriptionLabel, 0,0);
        m_pMainLayout->addWidget(m_pSaturationDescriptionLabel, 1,0);
        m_pMainLayout->addWidget(m_pOnOffDescriptionLabel,      2,0);


        m_pMainLayout->addWidget(m_pBrightnessSlider,   0,1);
        m_pMainLayout->addWidget(m_pSaturationSlider,   1,1);
        m_pMainLayout->addWidget(SwitchWidget,          2,1, Qt::AlignRight);
        break;
    }
    case CDeviceStructure::TEMPERATURESENSOR:
    {
        // NO BREAK --> uses same structure as Humidity
    }
    case CDeviceStructure::HUMIDITYSENSOR:
    {
        m_pOutputLabel = new QLabel(this);
        m_pOutputDescriptionLabel = new QLabel(this);

        m_pMainLayout = new QGridLayout();
        m_pMainLayout->addWidget(m_pOutputDescriptionLabel, 0,0);
        m_pMainLayout->addWidget(m_pOutputLabel, 0,1);

        break;
    }
    }
    setLayout(m_pMainLayout);

    UpdateDevice(_device);
}

void CDeviceView::UpdateDevice(CDeviceStructure::Device _device)
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
        CTempereraturSensor tempSensor(_device.m_DeviceNumber, _device.m_IpAddress.toString());
        m_pOutputDescriptionLabel->setText("Humidity:");
        m_pOutputLabel->setText(QString::number(tempSensor.getTemperature()) + "%");
        break;
    }
    case CDeviceStructure::HUMIDITYSENSOR:
    {
        CHumiditySensor humiditysensor(_device.m_DeviceNumber, _device.m_IpAddress.toString());
        m_pOutputDescriptionLabel->setText("Temperatur:");
        m_pOutputLabel->setText(QString::number(humiditysensor.getHumidity()) + " °C");
        break;
    }
    }
}
