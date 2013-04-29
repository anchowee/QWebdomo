QT       += core network

QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
LIBS += -lqwebdomo -lqxmpp

QMAKE_LIBDIR += ../../src
INCLUDEPATH += ../../src
