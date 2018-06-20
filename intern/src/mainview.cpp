#include "mainview.h"
#include "closemenueventfilter.h"

CMainView::CMainView(QWidget *parent) : QWidget(parent)
{
    m_pAppHeader = new CAppHeader(this);
    m_pMainWidgetStack = new QStackedLayout();

    m_pMenuBar = new CMenuBar(this);
    m_pMenuBar->hide();
    m_pMenuBar->move(0,0);
    m_pMenuBar->raise();


    m_pDeviceView = new CDeviceListView(this);
    m_pAboutView = new CAboutView(this);

    m_pMainWidgetStack->addWidget(m_pDeviceView);
    m_pMainWidgetStack->addWidget(m_pAboutView);

    m_pMainWidgetStack->setCurrentIndex(0);

    m_pMainLayout = new QVBoxLayout();

    m_pMainLayout->addWidget(m_pAppHeader);
    m_pMainLayout->addLayout(m_pMainWidgetStack, 1);

    setLayout(m_pMainLayout);

    CCloseMenuEventFilter* pEventFilter = new CCloseMenuEventFilter();

    qApp->installEventFilter(pEventFilter);


    connect(pEventFilter, SIGNAL(closeMenu()), this, SLOT(closeMenu()));
    connect(this, SIGNAL(sendIsMenuVisible(bool)), pEventFilter, SLOT(setIsMenuVisible(bool)));
    connect(m_pAppHeader, SIGNAL(MenuButtonPressed()), this, SLOT(triggerMenu()));

    connect(m_pMenuBar, SIGNAL(AboutButtonPressed()), this, SLOT(ShowAbout()));
    connect(m_pMenuBar, SIGNAL(DeviceButtonPressed()), this, SLOT(ShowDevices()));
}

void CMainView::resizeEvent(QResizeEvent *_event)
{
    auto tempWindow = qApp->activeWindow();
    if(tempWindow != 0)
    {
        QSize tempSize = qApp->activeWindow()->size();
        tempSize.setWidth(tempSize.width() * 0.7);
        m_pMenuBar->resize(tempSize);
        m_pMenuBar->raise();
    }

    QWidget::resizeEvent(_event);
}

void CMainView::triggerMenu()
{
    QSize tempSize = qApp->activeWindow()->size();
    tempSize.setWidth(tempSize.width() * 0.7);
    m_pMenuBar->resize(tempSize);
    m_pMenuBar->raise();

    openMenu();

}

void CMainView::closeMenu(bool _sendSignal)
{
    m_pMenuBar->hide();
    if(_sendSignal)
    {
        emit sendIsMenuVisible(false);
    }
}

void CMainView::openMenu()
{
    m_pMenuBar->show();
    emit sendIsMenuVisible(true);
}

void CMainView::ShowDevices()
{
    m_pMainWidgetStack->setCurrentWidget(m_pDeviceView);
    closeMenu(true);
}

void CMainView::ShowAbout()
{
    m_pMainWidgetStack->setCurrentWidget(m_pAboutView);
    closeMenu(true);
}

void CMainView::SleepModus()
{
    //turn off all Devices
    closeMenu(true);
}
