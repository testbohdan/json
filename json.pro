TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../../JSON/src/JSON.cpp \
    ../../JSON/src/JSONValue.cpp \
    ../../JSON/src/demo/example.cpp \

HEADERS += \
    ../../JSON/src/JSON.h \
    ../../JSON/src/JSONValue.h \
    ../../JSON/src/demo/functions.h

INCLUDEPATH +=  ../../JSON/src/
INCLUDEPATH +=  ../../JSON/src/demo
