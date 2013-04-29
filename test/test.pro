TEMPLATE = subdirs

SUBDIRS += \
    client

!isEmpty(QWD_USE_SERVER){
    SUBDIRS += server_example
}
