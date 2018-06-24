#include "devicelistview.h"

CDeviceListView::CDeviceListView(QWidget *parent) : QWidget(parent)
{
    m_pDevices = new CDeviceStructure();

    m_pDeviceToolBox = new QToolBox(this);

    m_pAddDeviceButton = new CCustomButton(this);
    m_pAddDeviceButton->setIcon(QIcon(":/addIcon"));

    m_pRemoveDeviceButton = new CCustomButton(this);
    m_pRemoveDeviceButton->setIcon(QIcon(":/removeIcon"));

    m_pDeviceListLayout = new QGridLayout();

    m_pDeviceListLayout->addWidget(m_pDeviceToolBox, 0, 0, 1, 2);
    m_pDeviceListLayout->addWidget(m_pAddDeviceButton, 1, 0, Qt::AlignCenter);
    m_pDeviceListLayout->addWidget(m_pRemoveDeviceButton, 1, 1, Qt::AlignCenter);

    m_pDeviceListLayout->setRowStretch(0, 1);

    QWidget* deviceListWidget = new QWidget(this);

    deviceListWidget->setLayout(m_pDeviceListLayout);

    m_pAddDeviceView = new CAddDeviceView(this);

    m_pMainStackLayout = new QStackedLayout();
    m_pMainStackLayout->addWidget(deviceListWidget);
    m_pMainStackLayout->addWidget(m_pAddDeviceView);

    setLayout(m_pMainStackLayout);

    connect(m_pAddDeviceButton,     SIGNAL(clicked(bool)),  this, SLOT(OpenAddDevice()));
    connect(m_pRemoveDeviceButton,  SIGNAL(clicked(bool)),  this, SLOT(RemoveDevice()));
    connect(m_pAddDeviceView,       SIGNAL(cancel()),       this, SLOT(CancelAddDevice()));

    connect(m_pAddDeviceView,       SIGNAL(sendDevice(CDeviceStructure::Device)), this, SLOT(AddDevice(CDeviceStructure::Device)));
}

void CDeviceListView::OpenAddDevice()
{
    m_pMainStackLayout->setCurrentIndex(1);
}

void CDeviceListView::RemoveDevice()
{
    int currentDevice = m_pDeviceToolBox->currentIndex();
    m_pDevices->deleteDevice(currentDevice);
    m_pDeviceToolBox->removeItem(currentDevice);
}

void CDeviceListView::CancelAddDevice()
{
    m_pMainStackLayout->setCurrentIndex(0);
}

void CDeviceListView::AddDevice(CDeviceStructure::Device _toAdd)
{
    m_pDevices->addDevices(_toAdd.m_Name, _toAdd.m_IpAddress, _toAdd.m_MacAddress, _toAdd.m_DeviceType, _toAdd.m_DeviceNumber);
    m_pMainStackLayout->setCurrentIndex(0);
    m_pDeviceToolBox->addItem(new QLabel(_toAdd.m_IpAddress.toString()), _toAdd.m_Name); //TODO: One Widget that gets constructed based on deviceType
}

void CDeviceListView::LoadDeviceList()
{
    for(auto& device: m_pDevices->returnDevices())
    {
        m_pDeviceToolBox->addItem(new QLabel(device.m_IpAddress.toString()), device.m_Name); //TODO: One Widget(CDeviceView) that gets constructed based on deviceType
    }
}

