TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

include(deployment.pri)
qtcAddDeployment()

SOURCES += main.cpp \
    lang/sequence.cpp \
    lang/parser.cpp \
    lang/context.cpp \
    lang/global_context.cpp \
    lang/data.cpp \
    lang/number.cpp \
    lang/boolean.cpp \
    lang/scavenger.cpp \
    lang/garbage.cpp \
    lang/function.cpp \
    lang/keyword.cpp

HEADERS += \
    lang/sequence.h \
    lang/parser.h \
    lang/utils.h \
    lang/context.h \
    lang/error.h \
    lang/function.h \
    lang/global_context.h \
    lang/funcs/plus.h \
    lang/arguments.h \
    lang/funcs/minus.h \
    lang/funcs/mul.h \
    lang/funcs/div.h \
    lang/number.h \
    lang/data.h \
    lang/boolean.h \
    lang/constant.h \
    lang/funcs/eq.h \
    lang/scavenger.h \
    lang/garbage.h \
    lang/funcs/if.h \
    lang/keyword.h \
    lang/symbol.h \
    lang/symbols.h

