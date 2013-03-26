TEMPLATE = lib
TARGET = WDDevices
QT +=
CONFIG += qt dll

HEADERS += \
    device.h \
    connecteddevice.h \
    networkconnecteddevice.h

SOURCES += \
    device.cpp \
    networkconnecteddevice.cpp \
    connecteddevice.cpp
