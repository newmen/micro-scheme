#ifndef MINUS_H
#define MINUS_H

#include "../fixed_arity_function.h"

struct Minus : public FixedArityFunction
{
    Minus();

protected:
    const Data *safeCall(const Context *context, const Arguments &args) const override;
};

#endif // MINUS_H
