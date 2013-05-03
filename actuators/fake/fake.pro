TEMPLATE        = lib
CONFIG         += plugin
INCLUDEPATH    += ../../src
LIBS += -lqwebdomo

TARGET = $$qtLibraryTarget(qwebdomo)

HEADERS += \
    QWFakeActuator.h

SOURCES += \
    QWFakeActuator.cpp

unix{
target.path = $$PREFIX/share/webdomo/plugins
}else{
#TODO: add target path
}

INSTALLS += target
