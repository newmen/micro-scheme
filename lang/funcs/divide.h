#ifndef DIVIDE_H
#define DIVIDE_H

#include "../fixed_arity_function.h"

struct Divide : public FixedArityFunction
{
    Divide();

protected:
    const Object *safeCall(const Context *context, const Objects &args) const override;
};

#endif // DIVIDE_H
