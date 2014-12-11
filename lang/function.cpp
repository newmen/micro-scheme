#include "function.h"

std::string Function::inspect() const
{
    return std::string("Function") + Object::inspect();
}

std::string Function::value() const
{
    return "ok";
}

const Data *Function::call(const Context *context) const
{
    return call(context, Arguments());
}
