#include "appheader.h"

CAppHeader::CAppHeader(QWidget *parent) : QWidget(parent)
{
    m_pAppNameLabel = new QLabel("SmHoEzMa", this);

    m_pNavigationButton = new QPushButton(this);
    m_pNavigationButton->setIconSize(QSize(96,96));
    m_pNavigationButton->setFocusPolicy(Qt::NoFocus);

    connect(m_pNavigationButton, SIGNAL(clicked(bool)), this, SIGNAL(MenuButtonPressed()));

    m_pMainLayout = new QHBoxLayout();
    setLayout(m_pMainLayout);

    m_pMainLayout->addWidget(m_pNavigationButton);
    m_pMainLayout->addWidget(m_pAppNameLabel, 1);

    m_pMainLayout->setContentsMargins(0,0,0,0);

    setNavigationMenu();
}

void CAppHeader::setNavigationMenu()
{
    m_pNavigationButton->setIcon(QIcon(":/menuIcon"));
}

void CAppHeader::setNavigationBack()
{
    m_pNavigationButton->setIcon(QIcon(":/backIcon"));
}
