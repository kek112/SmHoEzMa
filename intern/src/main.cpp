#include "mainwindow.h"
#include "pingmodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    PingModel model;
    QLabel *label = new QLabel(&w);



    label->setText(model.CheckForIP());


    //Display Content
    w.show();
    return a.exec();
}
