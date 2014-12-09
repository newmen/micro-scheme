#include "multiply.h"
#include "../number.h"
#include "../utils.h"

Multiply::Multiply() : FloatArityFunction(2)
{
}

const Object *Multiply::safeCall(const Context *context, const Objects &args) const
{
    double prod = 1;
    for (const Object *object : args)
    {
        prod *= Utils::getData(context, object)->getNumber();
    }

    return new Number(prod);
}
