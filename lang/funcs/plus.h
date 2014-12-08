#ifndef PLUS_H
#define PLUS_H

#include "../function.h"
#include "../default.h"
#include "../number.h"

struct Plus : public Default<Function>
{
    Plus() = default;

    const Object *call(const Arguments &args) const
    {
        double sum = 0;
        for (const Object *object : args)
        {
            sum += getData(object)->getNumber();
        }

        return new Number(sum);
    }
};

#endif // PLUS_H
