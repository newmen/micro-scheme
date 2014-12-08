#ifndef MINUS_H
#define MINUS_H

#include "../function.h"
#include "../number.h"

struct Minus : public FixedArityFunction
{
    Minus() : FixedArityFunction(2) {}

    const Data *call(const Arguments &args) const
    {
        checkArity(args);
        return new Number(args.front()->getNumber() - args.back()->getNumber());
    }
};

#endif // MINUS_H
