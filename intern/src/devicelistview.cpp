#include "devicelistview.h"

CDeviceListView::CDeviceListView(QWidget *parent) : QWidget(parent)
{
    m_pDeviceToolBox = new QToolBox(this);

    m_pAddDeviceButton = new QPushButton(this);
    m_pAddDeviceButton->setIcon(QIcon(":/add"));

    m_pRemoveDeviceButton = new QPushButton(this);
    m_pRemoveDeviceButton->setIcon(QIcon(":/remove"));

    m_pDeviceToolBox->addItem(new QLabel("test", this), "1. Item");
    m_pDeviceToolBox->addItem(new QLabel("test", this), "2. Item");

    m_pMainLayout = new QGridLayout();

    m_pMainLayout->addWidget(m_pDeviceToolBox, 0, 0, 1, 2);
    m_pMainLayout->addWidget(m_pAddDeviceButton, 1, 0, Qt::AlignCenter);
    m_pMainLayout->addWidget(m_pRemoveDeviceButton, 1, 1, Qt::AlignCenter);

    m_pMainLayout->setRowStretch(0, 1);

    setLayout(m_pMainLayout);
}
