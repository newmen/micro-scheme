#include "data.h"

std::string Data::inspect() const
{
    return value() + Garbage::inspect();
}

bool Data::getBoolean() const
{
    throw TypeError(value(), "boolean");
    return false;
}

double Data::getNumber() const
{
    throw TypeError(value(), "double");
    return 0;
}
