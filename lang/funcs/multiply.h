#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "../function.h"

struct Multiply : public Function
{
    Multiply() = default;

    const Object *call(const Context *context, const Objects &args) const override;
};

#endif // MULTIPLY_H
