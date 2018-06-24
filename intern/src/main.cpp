#include "mainwindow.h"
#include "pingmodel.h"
#include "androidsensor.h"
#include "philips.h"
#include "humiditysensor.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //PingModel model;
//    QLabel *label = new QLabel(&w);
//    CHumiditySensor *butz = new  CHumiditySensor(1,"192.168.178.64");
//    butz->getHumidity();


    //label->setText("IP"+model.CheckForIP());

    //butz->switchOff();

    //Display Content
    w.show();
    return a.exec();
}
