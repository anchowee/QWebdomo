#-------------------------------------------------
#
# Project created by QtCreator 2013-03-28T16:03:40
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = Utils
TEMPLATE = lib

DEFINES += UTILS_LIBRARY

SOURCES += threadedtcpserver.cpp \
    tcpserverthread.cpp

HEADERS += threadedtcpserver.h \
    tcpserverthread.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
