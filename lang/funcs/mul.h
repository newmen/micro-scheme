#ifndef MUL_H
#define MUL_H

#include "../function.h"
#include "../number.h"

struct Mul : public Function
{
    Mul() = default;

    const Data *call(const Arguments &args) const
    {
        double prod = 1;
        for (const Data *x : args)
        {
            prod *= x->getNumber();
        }

        return new Number(prod);
    }
};

#endif // MUL_H
