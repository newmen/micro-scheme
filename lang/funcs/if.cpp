#include "if.h"
#include "../utils.h"

If::If() : FixedArityFunction(3)
{
}

const Object *If::safeCall(const Context *context, const Objects &args) const
{
    Objects::const_iterator it = args.begin();
    const Data *condition = Utils::getData(context, *it);
    const Data *truthy = Utils::getData(context, *(++it));
    const Data *falsey = Utils::getData(context, *(++it));

    return condition->getBoolean() ? truthy : falsey;
}
