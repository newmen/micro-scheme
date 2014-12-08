#include "plus.h"
#include "../number.h"
#include "../utils.h"

const Object *Plus::call(const Context *context, const Objects &args) const
{
    double sum = 0;
    for (const Object *object : args)
    {
        sum += Utils::getData(context, object)->getNumber();
    }

    return new Number(sum);
}
