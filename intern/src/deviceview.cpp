#include "deviceview.h"
#include "humiditysensor.h"
#include "tempereratursensor.h"

#include <QDebug>
#include <QQuickView>


CDeviceView::CDeviceView(CDeviceStructure::Device _device, QWidget *parent)
    : QWidget(parent)
    , m_Device(_device)
    , m_Hue(0)
{
    m_pColorLamp = nullptr;
    m_pLuxLamp = nullptr;
    m_pHomecomingLamp = nullptr;

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
        m_pBrightnessSlider->setMinimum(0);
        m_pSaturationSlider->setMinimum(0);
        m_pBrightnessSlider->setMaximum(254);
        m_pSaturationSlider->setMaximum(254);

        m_pSwitchWidget = new CSwitchWidget(this);
        m_pSwitchWidget->setMinimumHeight(64);
        m_pSwitchWidget->setMinimumWidth(128);

//        m_pMapWidget = new QQuickWidget;
//        m_pMapWidget->setSource(QUrl("qrc:/map.qml"));
//        auto *view = new QQuickView;
//        auto *context = view->rootContext();
//        view->setSource(QUrl("qrc:/map.qml"));
//        QWidget *container = QWidget::createWindowContainer(view, this);
//        container->show();

//        auto *view = new QQuickView;
//        view->setSource(QUrl("qrc:/AndroidColorPicker.qml"));
//        m_pColorDialog = QWidget::createWindowContainer(view, this);
//        m_pColorDialog->hide();


//        m_pOpenColorDialog = new CCustomButton("Color", this);

//        QPalette pal = m_pOpenColorDialogButton->palette();
//        pal.setColor(QPalette::Button, QColor(Qt::blue));
//        m_pOpenColorDialogButton->setAutoFillBackground(true);
//        m_pOpenColorDialogButton->setPalette(pal);
//        m_pOpenColorDialogButton->update();

        m_pHueSlider = new QSlider(Qt::Horizontal, this);
        m_pHueSlider->setMinimum(0);
        m_pHueSlider->setMaximum(360);

        m_pHueSlider->setStyleSheet("border-image: url(:/ColorSpectrum);");

        m_pColorDialog = new QColorDialog(this);

        m_pMainLayout = new QGridLayout();

        m_pMainLayout->addWidget(m_pBrightnessDescriptionLabel, 0,0);
        m_pMainLayout->addWidget(m_pSaturationDescriptionLabel, 1,0);
        m_pMainLayout->addWidget(m_pColorDescriptionLabel,      2,0);
        m_pMainLayout->addWidget(m_pOnOffDescriptionLabel,      3,0);


        m_pMainLayout->addWidget(m_pBrightnessSlider,   0,1);
        m_pMainLayout->addWidget(m_pSaturationSlider,   1,1);
        m_pMainLayout->addWidget(m_pHueSlider,          2,1);
        m_pMainLayout->addWidget(m_pSwitchWidget,       3,1, Qt::AlignRight);

        //TODO: finish map (add set button & on/off switch)
//        m_pMainLayout->addWidget(container,          5,0, 1,2);


        connect(m_pSaturationSlider,    &QSlider::sliderReleased,   this, &CDeviceView::SettingsChanged);
        connect(m_pBrightnessSlider,    &QSlider::sliderReleased,   this, &CDeviceView::SettingsChanged);
        connect(m_pSwitchWidget,        &CSwitchWidget::released,   this, &CDeviceView::SettingsChanged);
        connect(m_pHueSlider,           &QSlider::sliderReleased,   this, &CDeviceView::SettingsChanged);
//        connect(m_pOpenColorDialogButton,   &QPushButton::clicked,      this, &CDeviceView::OpenColorDialog);


        break;
    }
    case CDeviceStructure::PHILIPLSLUXLAMP:
    {
        m_pBrightnessDescriptionLabel   = new QLabel("Brightness", this);
        m_pSaturationDescriptionLabel   = new QLabel("Saturation", this);
        m_pOnOffDescriptionLabel        = new QLabel("Active", this);


        m_pBrightnessSlider = new QSlider(Qt::Horizontal, this);
        m_pSaturationSlider = new QSlider(Qt::Horizontal, this);
        m_pBrightnessSlider->setMinimum(0);
        m_pSaturationSlider->setMinimum(0);
        m_pBrightnessSlider->setMaximum(254);
        m_pSaturationSlider->setMaximum(254);

        m_pSwitchWidget = new CSwitchWidget(this);
        m_pSwitchWidget->setMinimumHeight(64);
        m_pSwitchWidget->setMinimumWidth(128);

        m_pMainLayout = new QGridLayout();

        m_pMainLayout->addWidget(m_pBrightnessDescriptionLabel, 0,0);
        m_pMainLayout->addWidget(m_pSaturationDescriptionLabel, 1,0);
        m_pMainLayout->addWidget(m_pOnOffDescriptionLabel,      2,0);


        m_pMainLayout->addWidget(m_pBrightnessSlider,   0,1);
        m_pMainLayout->addWidget(m_pSaturationSlider,   1,1);
        m_pMainLayout->addWidget(m_pSwitchWidget,       2,1, Qt::AlignRight);


        connect(m_pSaturationSlider, &QSlider::sliderReleased, this, &CDeviceView::SettingsChanged);
        connect(m_pBrightnessSlider, &QSlider::sliderReleased, this, &CDeviceView::SettingsChanged);
        connect(m_pSwitchWidget,     &CSwitchWidget::released, this, &CDeviceView::SettingsChanged);

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
    m_Device = _device;
    SettingsChanged();
}

void CDeviceView::ReachedHome()
{
    if(m_pHomecomingLamp != nullptr)
    {
        delete m_pHomecomingLamp;
    }
    m_pHomecomingLamp = new CPhilips(nullptr, true, m_pBrightnessSlider->value(), m_pSaturationSlider->value(), m_Device.m_DeviceNumber, m_Device.m_IpAddress.toString());
    m_pSwitchWidget->setChecked(true);
    m_Device.m_Active = false;
}

void CDeviceView::SettingsChanged()
{
    if(m_pLuxLamp != nullptr)
    {
        delete m_pLuxLamp;
    }if(m_pColorLamp != nullptr)
    {
        delete m_pLuxLamp;
    }

    switch(m_Device.m_DeviceType)
    {
    case CDeviceStructure::PHILIPLSCLOLORLAMP:
    {
        m_Hue = m_pHueSlider->value() * 182; //normaly hue ranges from 0-360 (degree in a cricle 360 = 0) but philips hue lamps expect vlaues from 0 - 65535 (uint16) --> *182
        m_pColorLamp = new CPhilipsColor(this,
                                         m_pSwitchWidget->isChecked(),
                                         m_pBrightnessSlider->value(),
                                         m_pSaturationSlider->value(),
                                         m_Device.m_DeviceNumber,
                                         m_Device.m_IpAddress.toString(),
                                         m_Hue);
        break;
    }
    case CDeviceStructure::PHILIPLSLUXLAMP:
    {
        m_pLuxLamp = new CPhilipsLux(nullptr,
                                     m_pSwitchWidget->isChecked(),
                                     m_pBrightnessSlider->value(),
                                     m_pSaturationSlider->value(),
                                     m_Device.m_DeviceNumber,
                                     m_Device.m_IpAddress.toString());

        break;
    }
    case CDeviceStructure::TEMPERATURESENSOR:
    {
        CTemperatureSensor tempSensor(m_Device.m_DeviceNumber, m_Device.m_IpAddress.toString());
        m_pOutputDescriptionLabel->setText("Humidity:");
        m_pOutputLabel->setText(QString::number(tempSensor.getTemperature()) + "%");
        break;
    }
    case CDeviceStructure::HUMIDITYSENSOR:
    {
        CHumiditySensor humiditysensor(m_Device.m_DeviceNumber, m_Device.m_IpAddress.toString());
        m_pOutputDescriptionLabel->setText("Temperatur:");
        m_pOutputLabel->setText(QString::number(humiditysensor.getHumidity()) + " °C");
        break;
    }
    }
}

void CDeviceView::UpdatePosition()
{
    //    QGeoLocation geoLocation = qmlObject->property("location").value<QGeoLocation>();
}

void CDeviceView::OpenColorDialog()
{
//    auto color = m_pColorDialog->getColor();
    m_pColorDialog->resize(width(), m_pColorDialog->height());
    m_pColorDialog->show();

//    m_Hue = color.hue();

//    QPalette pal = m_pOpenColorDialog->palette();
//    pal.setColor(QPalette::Button, color);
//    m_pOpenColorDialog->setAutoFillBackground(true);
//    m_pOpenColorDialog->setPalette(pal);
//    m_pOpenColorDialog->update();

    SettingsChanged();
}
