#ifndef IF_H
#define IF_H

#include "../fixed_arity_function.h"

struct If : public FixedArityFunction
{
    If();

protected:
    const Data *safeCall(const Context *context, const Arguments &args) const override;
};

#endif // IF_H
