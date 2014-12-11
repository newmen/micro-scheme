#include "boolean.h"

Boolean::Boolean(bool value) : Constant(value)
{
}

std::string Boolean::value() const
{
    return _value ? "true" : "false";
}

bool Boolean::getBoolean() const
{
    return _value;
}
