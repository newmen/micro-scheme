#include "multiply.h"
#include "../number.h"
#include "../utils.h"

Multiply::Multiply() : FloatArityFunction(2)
{
}

const Data *Multiply::safeCall(const Context *context, const Arguments &args) const
{
    double prod = 1;
    for (const Symbol *symbol : args)
    {
        prod *= symbol->invoke(context)->getNumber();
    }

    return new Number(prod);
}
