#include "number.h"
#include "utils.h"

Number::Number(double value) : Constant(value)
{
}

const Data *Number::call(const Context *) const
{
    return this;
}

double Number::getNumber() const
{
    return _value;
}
