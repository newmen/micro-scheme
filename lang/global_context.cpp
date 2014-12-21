#include "global_context.h"
#include "funcs/plus.h"
#include "funcs/minus.h"
#include "funcs/multiply.h"
#include "funcs/divide.h"
#include "funcs/if.h"
#include "funcs/eq.h"
#include "funcs/define.h"
#include "funcs/lambda.h"

GlobalContext *GlobalContext::instance()
{
    bool filled = !destroyed();
    GlobalContext *inst = Singleton::instance();

    if (!filled)
    {
        inst->assign("+", new Plus());
        inst->assign("-", new Minus());
        inst->assign("*", new Multiply());
        inst->assign("/", new Divide());
        inst->assign("=", new Eq());
        inst->assign("if", new If());
        inst->assign("define", new Define());
        inst->assign("lambda", new Lambda());
    }

    return inst;
}

std::string GlobalContext::inspect() const
{
    return std::string("global") + Object::inspect();
}
