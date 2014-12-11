TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    lang/sequence.cpp \
    lang/parser.cpp \
    lang/context.cpp \
    lang/global_context.cpp \
    lang/data.cpp \
    lang/number.cpp \
    lang/boolean.cpp \
    lang/scavenger.cpp \
    lang/function.cpp \
    lang/keyword.cpp \
    lang/object.cpp \
    lang/fixed_arity_function.cpp \
    lang/user_function.cpp \
    lang/funcs/plus.cpp \
    lang/funcs/minus.cpp \
    lang/funcs/multiply.cpp \
    lang/funcs/divide.cpp \
    lang/funcs/if.cpp \
    lang/funcs/eq.cpp \
    lang/funcs/define.cpp \
    lang/utils.cpp \
    lang/float_arity_function.cpp

HEADERS += \
    lang/sequence.h \
    lang/parser.h \
    lang/utils.h \
    lang/context.h \
    lang/error.h \
    lang/function.h \
    lang/global_context.h \
    lang/funcs/plus.h \
    lang/funcs/minus.h \
    lang/number.h \
    lang/data.h \
    lang/boolean.h \
    lang/constant.h \
    lang/funcs/eq.h \
    lang/scavenger.h \
    lang/funcs/if.h \
    lang/keyword.h \
    lang/symbol.h \
    lang/object.h \
    lang/fixed_arity_function.h \
    lang/funcs/define.h \
    lang/keywords.h \
    lang/user_function.h \
    lang/funcs/divide.h \
    lang/funcs/multiply.h \
    lang/float_arity_function.h \
    lang/meta.h \
    lang/arguments.h

