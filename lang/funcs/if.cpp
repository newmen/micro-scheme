#include "if.h"
#include "../utils.h"

If::If() : FixedArityFunction(3)
{
}

const Object *If::safeCall(const Context *context, const Objects &args) const
{
    Objects::const_iterator it = args.begin();
    const Data *condition = Utils::getData(context, *it);
    const Object *truthy = *(++it);
    const Object *falsey = *(++it);

    return condition->getBoolean()
            ? Utils::getData(context, truthy)
            : Utils::getData(context, falsey);
}
