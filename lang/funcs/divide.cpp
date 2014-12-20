#include "divide.h"
#include "../number.h"
#include "../utils.h"

Divide::Divide() : Function(2)
{
}

const Data *Divide::safeCall(const Context *context, const Symbols &args) const
{
    const Data *first = args.front()->invoke(context);
    const Data *second = args.back()->invoke(context);
    return new Number(first->getNumber() / second->getNumber());
}
