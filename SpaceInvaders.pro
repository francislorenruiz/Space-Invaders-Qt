#-------------------------------------------------
#
# Project created by QtCreator 2014-11-19T11:47:35
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpaceInvaders
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Sjuego/Salien.cpp \
    Sjuego/Sbalas.cpp \
    Sjuego/Sescuadron.cpp \
    Sjuego/SI.cpp \
    Sjuego/Snave.cpp \
    Sjuego/Sjuego.cpp

HEADERS  += mainwindow.h \
    Sjuego/Salien.h \
    Sjuego/Sbalas.h \
    Sjuego/Sescuadron.h \
    Sjuego/SI.h \
    Sjuego/Snave.h \
    Sjuego/Sjuego.h
