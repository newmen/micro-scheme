TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
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
    lang/user_function.cpp \
    lang/funcs/plus.cpp \
    lang/funcs/minus.cpp \
    lang/funcs/multiply.cpp \
    lang/funcs/divide.cpp \
    lang/funcs/if.cpp \
    lang/funcs/eq.cpp \
    lang/funcs/define.cpp \
    lang/utils.cpp \
    lang/float_arity_function.cpp \
    lang/ok.cpp \
    helpers/micro_scheme.cpp \
    lang/variable.cpp \
    lang/scope.cpp \
    lang/closure.cpp \
    lang/statement.cpp \
    lang/funcs/lambda.cpp \
    lang/meta_function.cpp

HEADERS += \
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
    lang/funcs/define.h \
    lang/keywords.h \
    lang/user_function.h \
    lang/funcs/divide.h \
    lang/funcs/multiply.h \
    lang/float_arity_function.h \
    lang/ok.h \
    helpers/micro_scheme.h \
    lang/tools/singleton.h \
    lang/tools/no_base.h \
    lang/variable.h \
    lang/scope.h \
    lang/closure.h \
    lang/symbols.h \
    lang/statement.h \
    lang/funcs/lambda.h \
    lang/meta_function.h

