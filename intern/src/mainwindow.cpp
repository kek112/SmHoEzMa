#include "mainwindow.h"

#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    m_pMainView = new CMainView(this);
    setCentralWidget(m_pMainView);

//    m_pMainView->setStyleSheet("border: 1px solid red");
}

MainWindow::~MainWindow()
{

}
