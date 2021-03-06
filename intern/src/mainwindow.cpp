#include "mainwindow.h"

#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    m_pMainView = new CMainView(this);
    setCentralWidget(m_pMainView);

//    m_pMainView->setStyleSheet("border: 1px solid red"); // for debugging (shows a red border around every widget)


    // Stylesheet to customize Buttons and the spin box for android looks
    //background: #b3d2b2
    setStyleSheet( "QWidget {background: white; font-size: 20pt}"
                   "CCustomButton {border: none; background: transparent; min-height: 2em; min-width: 2em}"
                   "CCustomButton:pressed {border: 1px solid lightskyblue; background: lightblue;}"
                   "QSpinBox::down-button {subcontrol-origin: border; subcontrol-position: right; min-width: 75px; min-height: 75px}"
                   "QSpinBox::up-button {subcontrol-origin: border; subcontrol-position: left; min-width: 75px; min-height: 75px}");




//    QQuickWidget *mainWidget = new QQuickWidget(this);
//    mainWidget->setSource(QUrl("qrc:/map.qml"));
//    setCentralWidget(mainWidget);

}

MainWindow::~MainWindow()
{

}
