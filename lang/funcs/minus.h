#ifndef MINUS_H
#define MINUS_H

#include "../function.h"

struct Minus : public Function
{
    Minus();

protected:
    const Data *safeCall(const Context *context, const Symbols &args) const override;
};

#endif // MINUS_H
