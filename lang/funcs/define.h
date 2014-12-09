#ifndef DEFINE_H
#define DEFINE_H

#include "../float_arity_function.h"
#include "../meta.h"

struct Define : public Meta<FloatArityFunction>
{
    Define();

protected:
    const Object *safeCall(const Context *context, const Objects &args) const override;
};

#endif // DEFINE_H
