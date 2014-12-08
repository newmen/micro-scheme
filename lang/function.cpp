#include "function.h"

std::string Function::inspect() const
{
    return std::string("Function") + Object::inspect();
}

const Object *Function::call(const Context *context) const
{
    return call(context, Objects());
}
