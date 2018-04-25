#include "mainwindow.h"
#include "pingmodel.h"
#include "androidsensor.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //PingModel model;
    QLabel *label = new QLabel(&w);
    AndroidSensor butz;



    //label->setText("IP"+model.CheckForIP());


    //Display Content
    w.show();
    return a.exec();
}
