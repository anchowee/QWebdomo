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

unix{
target.path = $$PREFIX/share/webdomo/plugins
}else{
#TODO: add target path
}

INSTALLS += target
