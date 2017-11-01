#-------------------------------------------------
#
# Project created by QtCreator 2016-07-13T14:43:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = interpreter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    searchreplacedialog.cpp \
    goto.cpp \
    cfgdata.cpp \
    configfile.cpp \
    plaintext.cpp

HEADERS  += mainwindow.h \
    searchreplacedialog.h \
    goto.h \
    cfgdata.h \
    configfile.h \
    plaintext.h

FORMS    += mainwindow.ui \
    searchreplacedialog.ui \
    goto.ui
