#ifndef DEVICEVIEW_H
#define DEVICEVIEW_H

#include "custombutton.h"
#include "devicestructure.h"
#include "switchwidget.h"

#include "philipscolor.h"
#include "philipsLux.h"

#include <QColorDialog>
#include <QGridLayout>
#include <QLabel>
#include <QSlider>
#include <QWidget>
#include <QQuickWidget>
#include <QQuickItem>

#include <QQuickView>

class CDeviceView : public QWidget
{
    Q_OBJECT
public:
    explicit CDeviceView(CDeviceStructure::Device _device, QWidget *parent = nullptr);

signals:
    void DeviceChanged(CDeviceStructure::Device _device);

public slots:
    void UpdateDevice(CDeviceStructure::Device _device);
    void ReachedHome();
    void SettingsChanged();
    void UpdatePosition();
    void OpenColorDialog();

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
    CSwitchWidget*  m_pSwitchWidget;

    QLabel*         m_pColorDescriptionLabel;
    QSlider*        m_pHueSlider;
    CCustomButton*  m_pOpenColorDialogButton;

//    QQuickWidget*   m_pMapWidget;

    QWidget*        m_pColorDialog;

    CPhilipsColor*  m_pColorLamp;
    CPhilipsLux*    m_pLuxLamp;
    CPhilips*       m_pHomecomingLamp;

    int m_Hue;
};

#endif // DEVICEVIEW_H
