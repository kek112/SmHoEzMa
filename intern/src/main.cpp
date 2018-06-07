#include "mainwindow.h"
#include "pingmodel.h"
#include "androidsensor.h"
#include "philips.h"
#include "humiditysensor.h"
#include "devicestructure.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //PingModel model;
<<<<<<< HEAD
    //QLabel *label = new QLabel(&w);
    //CHumiditySensor *butz = new  CHumiditySensor(1,"192.168.178.64");
    CDeviceStructure *butz= new CDeviceStructure();
    //butz->getHumidity();
=======
//    QLabel *label = new QLabel(&w);
//    CHumiditySensor *butz = new  CHumiditySensor(1,"192.168.178.64");
//    butz->getHumidity();
>>>>>>> fixed pro file, started working on popup menu


    //label->setText("IP"+model.CheckForIP());

    //butz->switchOff();

    //Display Content
    w.show();
    return a.exec();
}
