#ifndef DEFINE_H
#define DEFINE_H

#include <assert.h>
#include "../meta_function.h"

struct Define : public MetaFunction
{
    Define();

protected:
    const Object *safeCall(const Context *context, const Objects &args) const override;
};

#endif // DEFINE_H
