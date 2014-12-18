#include "minus.h"
#include "../number.h"
#include "../utils.h"

Minus::Minus() : Function(2)
{
}

const Data *Minus::safeCall(const Context *context, const Arguments &args) const
{
    const Data *first = args.front()->invoke(context);
    const Data *second = args.back()->invoke(context);
    return new Number(first->getNumber() - second->getNumber());
}
