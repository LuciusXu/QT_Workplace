#-------------------------------------------------
#
# Project created by QtCreator 2021-11-11T23:10:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoinFlip
TEMPLATE = app


SOURCES += main.cpp\
        mainscene.cpp \
    mypushbutton.cpp \
    chooselevelscene.cpp \
    playscene.cpp

HEADERS  += mainscene.h \
    mypushbutton.h \
    chooselevelscene.h \
    playscene.h

FORMS    += mainscene.ui

RESOURCES += \
    res.qrc
