#-------------------------------------------------
#
# Project created by QtCreator 2016-12-23T00:01:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = laneDetection
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += D:/opencv/build/include
LIBS += -LD:/opencv/build/x64/vc14/lib\
 -lopencv_world310d
