#ifndef PLUS_H
#define PLUS_H

#include "../function.h"
#include "../number.h"

struct Plus : public Function
{
    Plus() = default;

    const Data *call(const Arguments &args) const
    {
        double sum = 0;
        for (const Data *x : args)
        {
            sum += x->getNumber();
        }

        return new Number(sum);
    }
};

#endif // PLUS_H
