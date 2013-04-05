QT       += core network

QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
LIBS += -lqwebdomo -lqxmpp -lavahi-common -lavahi-client -lavahi-qt4
