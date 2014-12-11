#ifndef PLUS_H
#define PLUS_H

#include "../float_arity_function.h"

struct Plus : public FloatArityFunction
{
    Plus();

protected:
    const Data *safeCall(const Context *context, const Arguments &args) const override;
};

#endif // PLUS_H
