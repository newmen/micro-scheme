#ifndef IF_H
#define IF_H

#include "../function.h"

struct If : public Function
{
    If();

protected:
    const Data *safeCall(const Context *context, const Arguments &args) const override;
};

#endif // IF_H
