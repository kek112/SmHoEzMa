#include "devicelistview.h"

#include "philips.h"

CDeviceListView::CDeviceListView(QWidget *parent) : QWidget(parent)
{
    m_pDevices = new CDeviceStructure();

    m_pDeviceToolBox = new QToolBox(this);

    m_pAddDeviceButton = new CCustomButton(this);
    m_pAddDeviceButton->setIcon(QIcon(":/addIcon"));

    m_pRemoveDeviceButton = new CCustomButton(this);
    m_pRemoveDeviceButton->setIcon(QIcon(":/removeIcon"));

    m_pDeviceListLayout = new QGridLayout();

    m_pDeviceListLayout->addWidget(m_pDeviceToolBox, 0, 0, 1, 2, Qt::AlignTop);
    m_pDeviceListLayout->addWidget(m_pAddDeviceButton, 1, 0, Qt::AlignCenter);
    m_pDeviceListLayout->addWidget(m_pRemoveDeviceButton, 1, 1, Qt::AlignCenter);

    m_pDeviceListLayout->setRowStretch(0, 1);

    QWidget* deviceListWidget = new QWidget(this);

    deviceListWidget->setLayout(m_pDeviceListLayout);

    m_pAddDeviceView = new CAddDeviceView(this);

    m_pMainStackLayout = new QStackedLayout();
    m_pMainStackLayout->addWidget(deviceListWidget);
    m_pMainStackLayout->addWidget(m_pAddDeviceView);

//    m_pMapThread = new CMapThread(m_pDevices);
//    m_pMapThread->moveToThread(&m_WorkerThread);
//    connect(&m_WorkerThread,    &QThread::finished,             m_pMapThread,   &QObject::deleteLater);
//    connect(this,               &CDeviceListView::startThread,  m_pMapThread,   &CMapThread::checkGPS);
//    connect(m_pMapThread,       &CMapThread::reachedHome,       this,           &CDeviceListView::ReachedHome);

//    m_WorkerThread.start();
//    emit startThread();

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
    m_pDevices->addDevices(_toAdd.m_Name, _toAdd.m_IpAddress, _toAdd.m_MacAddress, _toAdd.m_DeviceType, _toAdd.m_DeviceNumber, false, _toAdd.m_Coordinate);
    m_pMainStackLayout->setCurrentIndex(0);
    m_pDeviceToolBox->addItem(new CDeviceView(_toAdd), _toAdd.m_Name);
}

void CDeviceListView::ReachedHome(int _device)
{
    CDeviceView* deviceView = static_cast<CDeviceView*>(m_pDeviceToolBox->widget(_device));
    deviceView->ReachedHome();
}

void CDeviceListView::LoadDeviceList()
{
    for(auto& device: m_pDevices->returnDevices())
    {
        m_pDeviceToolBox->addItem(new CDeviceView(device), device.m_Name);
    }
}

