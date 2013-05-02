TEMPLATE        = lib
CONFIG         += plugin
INCLUDEPATH    += ../../src
LIBS += -lqwebdomo

TARGET = $$qtLibraryTarget(qwebdomo)

HEADERS += \
    QWFakeActuator.h

SOURCES += \
    QWFakeActuator.cpp
