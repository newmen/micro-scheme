#ifndef LAMBDA_H
#define LAMBDA_H

#include "../meta_function.h"

struct Lambda : public MetaFunction
{
    Lambda() = default;

protected:
    const Data *safeCall(const Context *context, const Symbols &args) const override;
};

#endif // LAMBDA_H
