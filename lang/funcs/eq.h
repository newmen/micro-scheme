#ifndef EQ_H
#define EQ_H

#include "../fixed_arity_function.h"

struct Eq : public FixedArityFunction
{
    Eq();

protected:
    const Data *safeCall(const Context *context, const Arguments &args) const override;
};

#endif // EQ_H
