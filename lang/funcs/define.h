#ifndef DEFINE_H
#define DEFINE_H

#include "../meta_function.h"

struct Define : public MetaFunction
{
    Define() = default;

protected:
    const Data *safeCall(const Context *context, const Symbols &args) const override;
};

#endif // DEFINE_H
