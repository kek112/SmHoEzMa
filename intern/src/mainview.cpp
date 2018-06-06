#include "mainview.h"

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

    connect(m_pAppHeader, SIGNAL(MenuButtonPressed()), this, SLOT(triggerMenu()));
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

void CMainView::mouseReleaseEvent(QMouseEvent *_event)
{
    if(_event->pos().x() > qApp->activeWindow()->size().width() * 0.7 && m_pMenuBar->isVisible())
    {
        m_pMenuBar->hide();
    }
    else
    {
        QWidget::mouseReleaseEvent(_event);
    }
}

void CMainView::triggerMenu()
{
    QSize tempSize = qApp->activeWindow()->size();
    tempSize.setWidth(tempSize.width() * 0.7);
    m_pMenuBar->resize(tempSize);
    m_pMenuBar->raise();

    m_pMenuBar->show();
}
