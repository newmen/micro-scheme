#ifndef DIV_H
#define DIV_H

#include "../fixed_arity_function.h"
#include "../default.h"
#include "../number.h"

struct Div : public Default<FixedArityFunction>
{
    Div() : Default(2) {}

    const Object *call(const Arguments &args) const
    {
        checkArity(args);

        const Data *first = getData(args.front());
        const Data *second = getData(args.back());
        return new Number(first->getNumber() / second->getNumber());
    }
};

#endif // DIV_H
