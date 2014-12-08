#ifndef MUL_H
#define MUL_H

#include "../function.h"
#include "../default.h"
#include "../number.h"

struct Mul : public Default<Function>
{
    Mul() = default;

    const Object *call(const Arguments &args) const
    {
        double prod = 1;
        for (const Object *object : args)
        {
            prod *= getData(object)->getNumber();
        }

        return new Number(prod);
    }
};

#endif // MUL_H
