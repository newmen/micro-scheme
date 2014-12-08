#include "global_context.h"
#include "funcs/plus.h"
#include "funcs/minus.h"
#include "funcs/multiply.h"
#include "funcs/divide.h"
#include "funcs/if.h"
#include "funcs/eq.h"
#include "funcs/define.h"

GlobalContext *GlobalContext::__instance = nullptr;
GlobalContext *GlobalContext::instance()
{
    if (!__instance)
    {
        __instance = new GlobalContext();
        __instance->assign("+", new Plus());
        __instance->assign("-", new Minus());
        __instance->assign("*", new Multiply());
        __instance->assign("/", new Divide());
        __instance->assign("if", new If());
        __instance->assign("=", new Eq());
        __instance->assign("define", new Define());
    }

    return __instance;
}

std::string GlobalContext::inspect() const
{
    return std::string("GlobalContext") + Object::inspect();
}
