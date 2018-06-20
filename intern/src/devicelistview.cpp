#include "devicelistview.h"

CDeviceListView::CDeviceListView(QWidget *parent) : QWidget(parent)
{
    m_pDeviceToolBox = new QToolBox(this);

    m_pAddDeviceButton = new QPushButton(this);
    m_pAddDeviceButton->setIcon(QIcon(":/addIcon"));
    m_pAddDeviceButton->setIconSize(QSize(96,96));
    m_pAddDeviceButton->setFocusPolicy(Qt::NoFocus);

    m_pRemoveDeviceButton = new QPushButton(this);
    m_pRemoveDeviceButton->setIcon(QIcon(":/removeIcon"));
    m_pRemoveDeviceButton->setIconSize(QSize(96,96));
    m_pRemoveDeviceButton->setFocusPolicy(Qt::NoFocus);

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
    m_pDevices->deleteDevice("currentDevice");
}

void CDeviceListView::CancelAddDevice()
{
    m_pMainStackLayout->setCurrentIndex(0);
}

void CDeviceListView::AddDevice(CDeviceStructure::Device _toAdd)
{
    m_pDevices->addDevices(_toAdd.m_Name, _toAdd.m_IpAddress, _toAdd.m_MacAddress, _toAdd.m_DeviceType, _toAdd.m_DeviceNumber);
}
