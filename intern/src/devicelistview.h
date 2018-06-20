#ifndef DEVICELISTVIEW_H
#define DEVICELISTVIEW_H

#include "adddeviceview.h"
#include "devicestructure.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedLayout>
#include <QToolBox>
#include <QWidget>

class CDeviceListView : public QWidget
{
    Q_OBJECT
public:
    explicit CDeviceListView(QWidget *parent = nullptr);

signals:

private slots:
    void OpenAddDevice();
    void RemoveDevice();
    void CancelAddDevice();
    void AddDevice(CDeviceStructure::Device _toAdd);

private:
    QStackedLayout* m_pMainStackLayout;
    QGridLayout*    m_pDeviceListLayout;

    QToolBox*       m_pDeviceToolBox;
    QPushButton*    m_pAddDeviceButton;
    QPushButton*    m_pRemoveDeviceButton;
    CAddDeviceView* m_pAddDeviceView;

    CDeviceStructure* m_pDevices;
};

#endif // DEVICELISTVIEW_H
