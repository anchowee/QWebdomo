TEMPLATE = lib
TARGET = WebdomoComponents
QT += qml quick
CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = Webdomo.Components

# Input
SOURCES += \
    qml_plugin.cpp \
    qwcontroller.cpp \
    qqwdeviceconfiguration.cpp \
    qqwappliance.cpp \
    qwappproperty.cpp \
    qwcommanderdevice.cpp

HEADERS += \
    qml_plugin.h \
    qwcontroller.h \
    qqwdeviceconfiguration.h \
    qqwappliance.h \
    qwappproperty.h \
    qwcommanderdevice.h

OTHER_FILES = qmldir

isEmpty(PREFIX) {
    unix {
        PREFIX = /usr
    } else {
        PREFIX = $$[QT_INSTALL_PREFIX]
    }
}

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

