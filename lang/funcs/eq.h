#ifndef EQ_H
#define EQ_H

#include "../fixed_arity_function.h"
#include "../default.h"
#include "../boolean.h"

class Eq : public Default<FixedArityFunction>
{
public:
    Eq() : Default(2) {}

    const Object *call(const Arguments &args) const
    {
        const Data *first = getData(args.front());
        const Data *second = getData(args.back());
        // TODO: not optimized comparison
        return new Boolean(first->value() == second->value());
    }
};

#endif // EQ_H
