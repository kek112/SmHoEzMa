#ifndef DEVICEVIEW_H
#define DEVICEVIEW_H

#include "devicestructure.h"

#include <QLabel>
#include <QWidget>

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

    QLabel* m_pLabel; //TODO: kann ich Label Nutzung kombinieren? (Für Temperatur + Humidity)
};

#endif // DEVICEVIEW_H
