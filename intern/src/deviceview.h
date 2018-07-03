#ifndef DEVICEVIEW_H
#define DEVICEVIEW_H

#include "devicestructure.h"
#include "switchwidget.h"

#include <QGridLayout>
#include <QLabel>
#include <QSlider>
#include <QWidget>
#include <QQuickWidget>
#include <QQuickItem>

class CDeviceView : public QWidget
{
    Q_OBJECT
public:
    explicit CDeviceView(CDeviceStructure::Device _device, QWidget *parent = nullptr);

signals:
    void DeviceChanged(CDeviceStructure::Device _device);

public slots:
    void UpdateDevice(CDeviceStructure::Device _device);

private:
    CDeviceStructure::Device m_Device;

    QGridLayout*    m_pMainLayout;

    QLabel*         m_pOutputDescriptionLabel;
    QLabel*         m_pOutputLabel;

    QLabel*         m_pBrightnessDescriptionLabel;
    QSlider*        m_pBrightnessSlider;

    QLabel*         m_pSaturationDescriptionLabel;
    QSlider*        m_pSaturationSlider;

    QLabel*         m_pOnOffDescriptionLabel;

    QLabel*         m_pColorDescriptionLabel;

    QObject*        m_pSwitchObject;
//    QQmlEngine      m_Engine;
//    QQmlComponent*  m_Component;
    //ColorDialog
};

#endif // DEVICEVIEW_H
