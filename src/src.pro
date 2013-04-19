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

SOURCES += $$PWD/QWDevice.cpp \
    $$PWD/QWDeviceConfiguration.cpp \
    QWActuator.cpp \
    QWAppliance.cpp \
    QWParser.cpp \
    QWActionParser.cpp

HEADERS += $$PWD/QWDevice.h \
    $$PWD/qwebdomo_global.h \
    $$PWD/QWDeviceConfiguration.h \
    QWActuator.h \
    QWAppliance.h \
    QWParser.h \
    QWActionParser.h

LIBS += -lqxmpp

!isEmpty(QWD_USE_SERVER){
    DEFINES += QWD_USE_SERVER
    include(server/server.pri)
}

!isEmpty(QWD_USE_COMMANDER){
    DEFINES += QWD_USE_COMMANDER
    include(commander/commander.pri)
}

# Installation prefix and library directory
isEmpty(PREFIX) {
    unix {
        PREFIX = /usr
    } else {
        PREFIX = $$[QT_INSTALL_PREFIX]
    }
}
isEmpty(LIBDIR) {
    LIBDIR = lib
}

#installation
headers.files = $$HEADERS
headers.path = $$PREFIX/include/qwebdomo
target.path = $$PREFIX/$$LIBDIR
INSTALLS += headers target
