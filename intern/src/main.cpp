#include "mainwindow.h"
#include "pingmodel.h"
#include <QDebug>
#include <QApplication>
#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    PingModel model;
    model.start_command();

    while(model.is_running())
    {
        qDebug()<<"Waiting";
    }

    qDebug()<<"Terminated";
    return a.exec();
}
