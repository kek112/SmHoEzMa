#include "menubar.h"

CMenuBar::CMenuBar(QWidget *parent) : QWidget(parent)
{
    //https://www.muecke-sturm.de/management-consulting/smart-home/
    QPixmap image(":/menuImage");
    m_pImageLabel = new QLabel(this);
    m_pImageLabel->setPixmap(image);
    m_pImageLabel->resize(size().width(), size().height() / 4);

    m_pDevicesButton = new QPushButton("Devices", this);
    m_pAboutButton   = new QPushButton("About", this);
    m_pSleepButton   = new QPushButton("Sleep", this);

    m_pDevicesButton->setFlat(true);
    m_pAboutButton  ->setFlat(true);
    m_pSleepButton  ->setFlat(true);

    m_pMainLayout = new QVBoxLayout();
    setLayout(m_pMainLayout);

    m_pMainLayout->addWidget(m_pImageLabel);
    m_pMainLayout->addWidget(m_pDevicesButton);
    m_pMainLayout->addWidget(m_pAboutButton);
    m_pMainLayout->addWidget(m_pSleepButton);

    setAutoFillBackground(true);
}

void CMenuBar::priavteButtonPressed()
{
}

void CMenuBar::resizeEvent(QResizeEvent *_event)
{
    m_pImageLabel->resize(size().width(), size().height() / 4);

    QWidget::resizeEvent(_event);
}
