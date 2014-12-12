#include "function.h"

std::string Function::inspect() const
{
    return std::string("Function") + Object::inspect();
}

std::string Function::value() const
{
    return "function";
}

bool Function::eql(const Data *other) const
{
    return this == other;
}

const Data *Function::call(const Context *context) const
{
    return call(context, Arguments());
}
