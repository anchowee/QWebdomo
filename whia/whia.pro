include(../QWebDomo.pri)

QT += network

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_LIBDIR += ../src
INCLUDEPATH += ../src
LIBS += -lqwebdomo -lqxmpp

TARGET += whia

SOURCES += \
    main.cpp \
    confparser.cpp

HEADERS += \
    confparser.h

OTHER_FILES += default_config/config \
    default_config/actuators.xml


