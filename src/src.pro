#-------------------------------------------------
#
# Project created by QtCreator 2013-04-02T13:33:31
#
#-------------------------------------------------

include(../QWebDomo.pri)

QT       -= gui
QT += network

TARGET = qwebdomo
VERSION = $${QW_VERSION}
TEMPLATE = lib

DEFINES += SRC_LIBRARY

SOURCES += $$PWD/QWDevice.cpp \
    $$PWD/QWDeviceConfiguration.cpp \
    $$PWD/QWActuator.cpp \
    $$PWD/QWAppliance.cpp \
    $$PWD/QWControlDevice.cpp

HEADERS += $$PWD/QWDevice.h \
    $$PWD/qwebdomo_global.h \
    $$PWD/QWDeviceConfiguration.h \
    $$PWD/QWActuator.h \
    $$PWD/QWAppliance.h \
    $$PWD/QWControlDevice.h

include(utils/utils.pri)

LIBS += -lqxmpp

!isEmpty(QWD_USE_SERVER){
    DEFINES += QWD_USE_SERVER
    include(server/server.pri)
}


#installation

headers.files = $$HEADERS
headers.path = $$PREFIX/include/qwebdomo
target.path = $$PREFIX/$$LIBDIR
INSTALLS += headers target
