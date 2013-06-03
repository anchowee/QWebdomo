#-------------------------------------------------
#
# Project created by QtCreator 2013-04-02T13:33:31
#
#-------------------------------------------------

include(../QWebDomo.pri)

QT += network

TARGET = qwebdomo
VERSION = $${QW_VERSION}
TEMPLATE = lib
CONFIG += $$QW_LIBRARY_TYPE

DEFINES += SRC_LIBRARY

SOURCES += $$PWD/QWDevice.cpp \
    $$PWD/QWDeviceConfiguration.cpp

HEADERS += $$PWD/QWDevice.h \
    $$PWD/qwebdomo_global.h \
    $$PWD/QWDeviceConfiguration.h

LIBS += -lqxmpp

!isEmpty(QW_SERVER){
    DEFINES += QW_SERVER
    include(server/server.pri)
}

!isEmpty(QW_DEVICE){
    include(device/device.pri)
}


#installation

headers.files = $$HEADERS
headers.path = $$PREFIX/include/qwebdomo
target.path = $$PREFIX/$$LIBDIR
INSTALLS += headers target
