#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "../float_arity_function.h"

struct Multiply : public FloatArityFunction
{
    Multiply();

protected:
    const Data *safeCall(const Context *context, const Symbols &args) const override;
};

#endif // MULTIPLY_H
