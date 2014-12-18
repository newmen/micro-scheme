#include "ok.h"

Ok *Ok::__instance = nullptr;
Ok *Ok::instance()
{
    if (!__instance)
    {
        __instance = new Ok();
    }

    return __instance;
}

std::string Ok::value() const
{
    return "ok";
}

bool Ok::eql(const Data *) const
{
    return false;
}
