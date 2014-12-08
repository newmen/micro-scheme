#include "eq.h"
#include "../boolean.h"
#include "../utils.h"

Eq::Eq() : FixedArityFunction(2)
{
}

const Object *Eq::safeCall(const Context *context, const Objects &args) const
{
    const Data *first = Utils::getData(context, args.front());
    const Data *second = Utils::getData(context, args.back());
    // TODO: not optimized comparison
    return new Boolean(first->value() == second->value());
}
