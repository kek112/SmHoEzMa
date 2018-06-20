#include "mainwindow.h"

#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    m_pMainView = new CMainView(this);
    setCentralWidget(m_pMainView);

//    m_pMainView->setStyleSheet("border: 1px solid red");
    setStyleSheet( "QWidget {background: white}"
                   "QPushButton {border: none; background: transparent; min-height: 2em; min-width: 2em}"
                   "QPushButton:pressed {border: 1px solid lightskyblue; background: lightblue;}"
                   "QPushButton:focus {border: none;}"
                   "QPushButton:focus:pressed {border: none;}"
                   "QPushButton:hover {border: none;}"
                   "QPushButton:edit-focus {border: none;}");

//    QQuickWidget *view = new QQuickWidget;
//    view->setSource(QUrl("qrc:/MainView.qml"));
//    setCentralWidget(view);

}

MainWindow::~MainWindow()
{

}
