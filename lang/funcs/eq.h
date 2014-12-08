#ifndef EQ_H
#define EQ_H

#include "../function.h"
#include "../boolean.h"

class Eq : public FixedArityFunction
{
public:
    Eq() : FixedArityFunction(2) {}

    const Data *call(const Arguments &args) const
    {
        return new Boolean(args.front()->value() == args.back()->value());
    }
};

#endif // EQ_H
