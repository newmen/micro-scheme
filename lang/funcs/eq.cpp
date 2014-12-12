#include "eq.h"
#include "../boolean.h"
#include "../utils.h"

Eq::Eq() : FixedArityFunction(2)
{
}

const Data *Eq::safeCall(const Context *context, const Arguments &args) const
{
    const Data *first = args.front()->invoke(context);
    const Data *second = args.back()->invoke(context);
    return new Boolean(first->eql(second));
}
