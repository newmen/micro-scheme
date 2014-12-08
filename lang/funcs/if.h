#ifndef IF_H
#define IF_H

#include "../fixed_arity_function.h"

struct If : public FixedArityFunction
{
    If();

protected:
    const Object *safeCall(const Context *context, const Objects &args) const override;
};

#endif // IF_H
