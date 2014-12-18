#ifndef DIVIDE_H
#define DIVIDE_H

#include "../function.h"

struct Divide : public Function
{
    Divide();

protected:
    const Data *safeCall(const Context *context, const Arguments &args) const override;
};

#endif // DIVIDE_H
