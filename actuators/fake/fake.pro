TEMPLATE        = lib
CONFIG         += plugin
INCLUDEPATH    += ../../src
LIBS += -lqwebdomo

TARGET = $$qtLibraryTarget(fake)

HEADERS += \
    QWFakeActuator.h

SOURCES += \
    QWFakeActuator.cpp

include(../../QWebDomo.pri)

target.path = $${PLUGINS_PATH}

INSTALLS += target

OTHER_FILES += \
    fakeActuator.json
