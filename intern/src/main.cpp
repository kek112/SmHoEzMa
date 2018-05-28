#include "mainwindow.h"
#include "pingmodel.h"
#include "androidsensor.h"
#include "phillips.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //PingModel model;
    QLabel *label = new QLabel(&w);
    CPhillips *butz = new CPhillips(&w,true,240,240,false,1,"192.168.178.64");



    //label->setText("IP"+model.CheckForIP());

    //butz->switchOff();

    //Display Content
    w.show();
    return a.exec();
}
