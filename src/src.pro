#-------------------------------------------------
#
# Project created by QtCreator 2013-04-02T13:33:31
#
#-------------------------------------------------

QT       -= gui
QT += network

TARGET = qwebdomo
TEMPLATE = lib

DEFINES += SRC_LIBRARY

SOURCES += device.cpp \
    connecteddevice.cpp \

HEADERS += device.h \
    qwebdomo_global.h \
    connecteddevice.h \

LIBS += -lqxmpp

!isEmpty(QWD_USE_SERVER){
    DEFINES += QWD_USE_SERVER
    include(server/server.pri)
}
