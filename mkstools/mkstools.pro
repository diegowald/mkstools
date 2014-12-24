#-------------------------------------------------
#
# Project created by QtCreator 2014-11-23T08:09:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = mkstools
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    commands/basecommand.cpp \
    commands/maincommand.cpp \
    widgets/maincommandwidget.cpp \
    commands/commands.cpp \
    commands/hacommand.cpp \
    commands/vigacommand.cpp \
    dialogs/dlgnewproject.cpp \
    dialogs/dlgnewelement.cpp \
    model/base.cpp \
    model/tipologias/tipologia.cpp \
    model/elemento.cpp \
    model/proyecto.cpp \
    model/esquemas_estructurales/esquemaestructural.cpp \
    model/solicitaciones/solicitacion.cpp \
    model/secciones/seccion.cpp \
    model/tipologias/viga.cpp \
    dialogs/dlgedittopologia.cpp \
    model/esquemas_estructurales/vigasimplementeapoyada.cpp \
    dialogs/dlgeditvigasimplementeapoyada.cpp \
    model/secciones/seccionrectangular.cpp \
    dialogs/dlgeditseccionrectangular.cpp \
    model/solicitaciones/cargauniformeconstante.cpp \
    model/solicitaciones/cargapuntual.cpp \
    dialogs/dlgeditorsolicitaciones.cpp \
    dialogs/dlgcargapuntual.cpp \
    dialogs/dlgeditcargauniformedistribuida.cpp \
    model/materiales/material.cpp \
    model/materiales/acero.cpp \
    model/materiales/hormigon.cpp \
    model/materiales/hormigonarmado.cpp \
    dialogs/dlgeditacero.cpp \
    dialogs/dlgedithormigonarmado.cpp \
    model/metodosCalculo/metodocalculo.cpp \
    model/metodosCalculo/hametodoclasico.cpp \
    model/esfuerzos_internos/esfuerzointerno.cpp \
    factory.cpp \
    commands/calcularcommand.cpp \
    dialogs/dlgresults.cpp \
    dialogs/dlgdiagramas.cpp \
    dialogs/dlgsetarmadurasfelxion.cpp

HEADERS  += mainwindow.h \
    commands/basecommand.h \
    commands/maincommand.h \
    widgets/maincommandwidget.h \
    commands/commands.h \
    commands/hacommand.h \
    commands/vigacommand.h \
    dialogs/dlgnewproject.h \
    dialogs/dlgnewelement.h \
    model/base.h \
    model/tipologias/tipologia.h \
    model/elemento.h \
    model/proyecto.h \
    model/esquemas_estructurales/esquemaestructural.h \
    model/solicitaciones/solicitacion.h \
    model/secciones/seccion.h \
    model/tipologias/viga.h \
    dialogs/dlgedittopologia.h \
    model/IClonable.h \
    model/esquemas_estructurales/vigasimplementeapoyada.h \
    dialogs/dlgeditvigasimplementeapoyada.h \
    model/secciones/seccionrectangular.h \
    dialogs/dlgeditseccionrectangular.h \
    model/solicitaciones/cargauniformeconstante.h \
    model/solicitaciones/cargapuntual.h \
    dialogs/dlgeditorsolicitaciones.h \
    dialogs/dlgcargapuntual.h \
    dialogs/dlgeditcargauniformedistribuida.h \
    model/materiales/material.h \
    model/materiales/acero.h \
    model/materiales/hormigon.h \
    model/materiales/hormigonarmado.h \
    dialogs/dlgeditacero.h \
    dialogs/dlgedithormigonarmado.h \
    model/metodosCalculo/metodocalculo.h \
    model/metodosCalculo/hametodoclasico.h \
    model/forward.h \
    model/esfuerzos_internos/esfuerzointerno.h \
    factory.h \
    commands/calcularcommand.h \
    dialogs/dlgresults.h \
    dialogs/dlgdiagramas.h \
    dialogs/dlgsetarmadurasfelxion.h

FORMS    += mainwindow.ui \
    widgets/maincommandwidget.ui \
    dialogs/dlgnewproject.ui \
    dialogs/dlgnewelement.ui \
    dialogs/dlgedittopologia.ui \
    dialogs/dlgeditvigasimplementeapoyada.ui \
    dialogs/dlgeditseccionrectangular.ui \
    dialogs/dlgeditorsolicitaciones.ui \
    dialogs/dlgcargapuntual.ui \
    dialogs/dlgeditcargauniformedistribuida.ui \
    dialogs/dlgeditacero.ui \
    dialogs/dlgedithormigonarmado.ui \
    dialogs/dlgresults.ui \
    dialogs/dlgdiagramas.ui \
    dialogs/dlgsetarmadurasfelxion.ui
