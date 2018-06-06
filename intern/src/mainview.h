#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "aboutview.h"
#include "appheader.h"
#include "devicelistview.h"
#include "menubar.h"

#include <QApplication>
#include <QDebug>
#include <QResizeEvent>
#include <QStackedLayout>
#include <QVBoxLayout>
#include <QWidget>

class CMainView : public QWidget
{
    Q_OBJECT
public:
    explicit CMainView(QWidget *parent = nullptr);

signals:

protected:
    void resizeEvent(QResizeEvent* _event);
    void mouseReleaseEvent(QMouseEvent* _event);

private slots:
    void triggerMenu();

private:
    CAppHeader*         m_pAppHeader;
    QStackedLayout*     m_pMainWidgetStack;

    CMenuBar*           m_pMenuBar;

    CDeviceListView*    m_pDeviceView;
    CAboutView*         m_pAboutView;

    QVBoxLayout*        m_pMainLayout;
};

#endif // MAINVIEW_H
