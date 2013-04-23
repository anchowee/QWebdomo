TEMPLATE = subdirs

SUBDIRS += src test

!isEmpty(WITH_QML_PLUGINS){
    SUBDIRS += qml
}
