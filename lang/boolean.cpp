#include "boolean.h"

Boolean::Boolean(bool value) : Constant(value)
{
}

bool Boolean::getBoolean() const
{
    return _value;
}
