TEMPLATE = subdirs

SUBDIRS += src test

!isEmpty(QML_PLUGINS){
    SUBDIRS += qml
}
