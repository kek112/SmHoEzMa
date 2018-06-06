#include "mainwindow.h"

#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    m_pMainView = new CMainView(this);
    setCentralWidget(m_pMainView);
}

MainWindow::~MainWindow()
{

}
