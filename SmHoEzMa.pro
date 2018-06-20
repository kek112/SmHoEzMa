#-------------------------------------------------
#
# Project created by QtCreator 2018-04-17T15:05:29
#
#-------------------------------------------------
#
#
#       HIER EINFÜGEN
#
QT       += core gui network positioning xml quickwidgets
#
#       HIER EINFÜGEN
#
#
#
















greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmHoEzMa
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += qtc_runnable

SOURCES += \
        intern/src/main.cpp \
        intern/src/mainwindow.cpp \
    intern/src/pingmodel.cpp \
    intern/src/androidsensor.cpp \
    intern/src/devicestructure.cpp \
    intern/src/phillips.cpp \
    intern/src/phillipscolor.cpp \
    intern/src/phillipsLux.cpp \
    intern/src/humiditysensor.cpp \
    intern/src/aboutview.cpp \
    intern/src/adddeviceview.cpp \
    intern/src/appheader.cpp \
    intern/src/closemenueventfilter.cpp \
    intern/src/devicelistview.cpp \
    intern/src/mainview.cpp \
    intern/src/menubar.cpp

HEADERS += \
        intern/src/mainwindow.h \
    intern/src/pingmodel.h \
    intern/src/androidsensor.h \
    intern/src/devicestructure.h \
    intern/src/phillips.h \
    intern/src/phillipscolor.h \
    intern/src/phillipsLux.h \
    intern/src/humiditysensor.h \
    intern/src/aboutview.h \
    intern/src/adddeviceview.h \
    intern/src/appheader.h \
    intern/src/closemenueventfilter.h \
    intern/src/devicelistview.h \
    intern/src/mainview.h \
    intern/src/menubar.h

include(Project_Compile_Settings_Sahm.pri)
#include(C:\Users\Tobias\Documents\Development\C++\SmHoEzMa\extern\qt-material-widgets\components\components.pri)

RESOURCES += \
    intern/assets/icons/icons.qrc \
    intern/src/qml.qrc
