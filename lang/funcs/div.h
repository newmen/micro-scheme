#ifndef DIV_H
#define DIV_H

#include "../function.h"
#include "../number.h"

struct Div : public FixedArityFunction
{
    Div() : FixedArityFunction(2) {}

    const Data *call(const Arguments &args) const
    {
        checkArity(args);
        return new Number(args.front()->getNumber() / args.back()->getNumber());
    }
};

#endif // DIV_H
