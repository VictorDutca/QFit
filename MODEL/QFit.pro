#-------------------------------------------------
#
# Project created by QtCreator 2020-03-28T10:02:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFit
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

CONFIG += warn_off

SOURCES += \
        main.cpp \
    workout.cpp \
    corsa.cpp \
    nuoto.cpp \
    ciclismo.cpp \
    triathlon.cpp \
    qfitwindow.cpp \
    xmlhandler.cpp \
    qfitmenu.cpp \
    modelworkout.cpp \
    qfitedit.cpp \
    qfitcorsa.cpp \
    qfitciclismo.cpp \
    qfitnuoto.cpp \
    qfittriathlon.cpp \
    delegatedelete.cpp \
    delegatebutton.cpp \
    delegatechange.cpp \
    qfitchangecorsa.cpp \
    qfitchangeciclismo.cpp \
    qfitchangenuoto.cpp \
    qfitchangetriathlon.cpp \
    delegateview.cpp

HEADERS += \
    workout.h \
    corsa.h \
    nuoto.h \
    ciclismo.h \
    triathlon.h \
    lista.h \
    qfitwindow.h \
    xmlhandler.h \
    qfitmenu.h \
    modelworkout.h \
    qfitedit.h \
    qfitcorsa.h \
    qfitciclismo.h \
    qfitnuoto.h \
    qfittriathlon.h \
    delegatedelete.h \
    delegatebutton.h \
    delegatechange.h \
    qfitchangecorsa.h \
    qfitchangeciclismo.h \
    errhandler.h \
    qfitchangenuoto.h \
    qfitchangetriathlon.h \
    delegateview.h

FORMS +=

RESOURCES += \
    utils.qrc

DISTFILES +=
