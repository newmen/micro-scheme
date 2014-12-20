#ifndef DEFINE_H
#define DEFINE_H

#include "../float_arity_function.h"
#include "../meta.h"

struct Define : public Meta<FloatArityFunction>
{
    Define();

protected:
    const Data *safeCall(const Context *context, const Symbols &args) const override;
};

#endif // DEFINE_H
