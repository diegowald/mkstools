#-------------------------------------------------
#
# Project created by QtCreator 2014-11-23T08:09:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mkstools
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    commands/basecommand.cpp \
    commands/maincommand.cpp

HEADERS  += mainwindow.h \
    commands/basecommand.h \
    commands/maincommand.h

FORMS    += mainwindow.ui
