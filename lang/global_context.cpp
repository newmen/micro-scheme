#include "global_context.h"
#include "funcs/plus.h"
#include "funcs/minus.h"
#include "funcs/mul.h"
#include "funcs/div.h"
#include "funcs/if.h"
#include "funcs/eq.h"

GlobalContext *GlobalContext::__instance = nullptr;
GlobalContext *GlobalContext::instance()
{
    if (!__instance)
    {
        __instance = new GlobalContext();
        __instance->assign("+", new Plus());
        __instance->assign("-", new Minus());
        __instance->assign("*", new Mul());
        __instance->assign("/", new Div());
        __instance->assign("if", new If());
        __instance->assign("=", new Eq());
    }

    return __instance;
}

std::string GlobalContext::inspect() const
{
    return std::string("GlobalContext") + Object::inspect();
}
