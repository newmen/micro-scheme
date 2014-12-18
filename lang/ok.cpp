#include "ok.h"

std::string Ok::value() const
{
    return "ok";
}

bool Ok::eql(const Data *) const
{
    return false;
}
