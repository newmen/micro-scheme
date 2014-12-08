#include "divide.h"
#include "../number.h"
#include "../utils.h"

Divide::Divide() : FixedArityFunction(2)
{
}

const Object *Divide::safeCall(const Context *context, const Objects &args) const
{
    const Data *first = Utils::getData(context, args.front());
    const Data *second = Utils::getData(context, args.back());
    return new Number(first->getNumber() / second->getNumber());
}
