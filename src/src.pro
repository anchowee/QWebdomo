#-------------------------------------------------
#
# Project created by QtCreator 2013-04-02T13:33:31
#
#-------------------------------------------------

QT       -= gui

TARGET = qwebdomo
TEMPLATE = lib

DEFINES += SRC_LIBRARY

SOURCES += device.cpp \
    connecteddevice.cpp \

HEADERS += device.h \
    qwebdomo_global.h \
    connecteddevice.h \

!isEmpty(QWEBDOMO_ENABLE_XMPP){
    DEFINES += ENABLE_XMPP
    include(xmpp/xmpp.pri)
}

!isEmpty(QWEBDOMO_ENABLE_SERIAL){
    DEFINES += ENABLE_SERIAL
    include(serial/serial.pri)
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
