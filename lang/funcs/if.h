#ifndef IF_H
#define IF_H

#include "../function.h"

class If : public FixedArityFunction
{
public:
    If() : FixedArityFunction(3) {}

    const Data *call(const Arguments &args) const
    {
        Arguments::const_iterator it = args.begin();
        const Data *condition = *it;
        const Data *truthy = *(++it);
        const Data *falsey = *(++it);

        return condition->getBoolean() ? truthy : falsey;
    }
};

#endif // IF_H
