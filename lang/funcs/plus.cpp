#include "plus.h"
#include "../number.h"
#include "../utils.h"

Plus::Plus() : FloatArityFunction(2)
{
}

const Data *Plus::safeCall(const Context *context, const Arguments &args) const
{
    double sum = 0;
    for (const Symbol *symbol : args)
    {
        sum += symbol->invoke(context)->getNumber();
    }

    return new Number(sum);
}
