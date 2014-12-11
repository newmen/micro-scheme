#include "number.h"
#include "utils.h"

Number::Number(double value) : Constant(value)
{
}

double Number::getNumber() const
{
    return _value;
}
