#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "../float_arity_function.h"

struct Multiply : public FloatArityFunction
{
    Multiply();

protected:
    const Object *safeCall(const Context *context, const Objects &args) const override;
};

#endif // MULTIPLY_H
