#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "aboutview.h"
#include "appheader.h"
#include "devicelistview.h"
#include "menubar.h"

#include <QApplication>
#include <QDebug>
#include <QPropertyAnimation>
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
    void sendIsMenuVisible(bool _visible);

protected:
    void resizeEvent(QResizeEvent* _event);

private slots:
    void triggerMenu();
    void closeMenu(bool _sendSignal = false);
    void openMenu();

    void ShowDevices();
    void ShowAbout();

    void SleepModus();

private:
    CAppHeader*         m_pAppHeader;
    QStackedLayout*     m_pMainWidgetStack;

    CMenuBar*           m_pMenuBar;

    CDeviceListView*    m_pDeviceView;
    CAboutView*         m_pAboutView;

    QVBoxLayout*        m_pMainLayout;

    QPropertyAnimation* m_pAnimation;
};

#endif // MAINVIEW_H
