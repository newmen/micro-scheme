#ifndef EQ_H
#define EQ_H

#include "../function.h"

struct Eq : public Function
{
    Eq();

protected:
    const Data *safeCall(const Context *context, const Symbols &args) const override;
};

#endif // EQ_H
