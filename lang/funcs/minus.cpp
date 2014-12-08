#include "minus.h"
#include "../number.h"
#include "../utils.h"

Minus::Minus() : FixedArityFunction(2)
{
}

const Object *Minus::safeCall(const Context *context, const Objects &args) const
{
    const Data *first = Utils::getData(context, args.front());
    const Data *second = Utils::getData(context, args.back());
    return new Number(first->getNumber() - second->getNumber());
}
