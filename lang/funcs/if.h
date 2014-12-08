#ifndef IF_H
#define IF_H

#include "../fixed_arity_function.h"
#include "../default.h"

class If : public Default<FixedArityFunction>
{
public:
    If() : Default(3) {}

    const Object *call(const Arguments &args) const
    {
        Arguments::const_iterator it = args.begin();
        const Data *condition = getData(*it);
        const Data *truthy = getData(*(++it));
        const Data *falsey = getData(*(++it));

        return condition->getBoolean() ? truthy : falsey;
    }
};

#endif // IF_H
