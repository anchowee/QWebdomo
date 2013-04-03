LIBS += -ldns_sd

SOURCES += $$PWD/qwserver.cpp \
    $$PWD/bonjourserviceregister.cpp

HEADERS += $$PWD/qwserver.h \
    $$PWD/bonjourserviceregister.h \
    $$PWD/bonjourrecord.h

unix {
    LIBS += -ldns_sd
}
