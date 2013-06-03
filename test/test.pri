include(../QWebDomo.pri)

QT       += core network

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
LIBS += -lqwebdomo -lqxmpp

QMAKE_LIBDIR += ../../core
