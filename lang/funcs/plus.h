#ifndef PLUS_H
#define PLUS_H

#include "../function.h"

struct Plus : public Function
{
    Plus() = default;

    const Object *call(const Context *context, const Objects &args) const override;
};

#endif // PLUS_H
