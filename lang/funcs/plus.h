#ifndef PLUS_H
#define PLUS_H

#include "../float_arity_function.h"

struct Plus : public FloatArityFunction
{
    Plus();

protected:
    const Object *safeCall(const Context *context, const Objects &args) const override;
};

#endif // PLUS_H
