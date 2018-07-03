#ifndef DEVICELISTVIEW_H
#define DEVICELISTVIEW_H

#include "adddeviceview.h"
#include "custombutton.h"
#include "devicestructure.h"
#include "deviceview.h"

#include <QGridLayout>
#include <QLabel>
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
    void LoadDeviceList();

    QStackedLayout* m_pMainStackLayout;
    QGridLayout*    m_pDeviceListLayout;

    QToolBox*       m_pDeviceToolBox;
    CCustomButton*  m_pAddDeviceButton;
    CCustomButton*  m_pRemoveDeviceButton;
    CAddDeviceView* m_pAddDeviceView;

    CDeviceStructure* m_pDevices;
};

#endif // DEVICELISTVIEW_H
