TEMPLATE        = lib
CONFIG         += plugin
QT += serialport

INCLUDEPATH    += ../../src
QMAKE_LIBDIR += ../../src
LIBS += -lqwebdomo

TARGET = $$qtLibraryTarget(GME-thermostat)

HEADERS += \ 
    thermostatactuator.h

SOURCES += \ 
    thermostatactuator.cpp

include(../../QWebDomo.pri)

target.path = $${PLUGINS_PATH}

INSTALLS += target

OTHER_FILES += \
    GME-thermostatActuator.json
