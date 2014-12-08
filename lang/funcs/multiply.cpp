#include "multiply.h"
#include "../number.h"
#include "../utils.h"

const Object *Multiply::call(const Context *context, const Objects &args) const
{
    double prod = 1;
    for (const Object *object : args)
    {
        prod *= Utils::getData(context, object)->getNumber();
    }

    return new Number(prod);
}
