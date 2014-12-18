#include "if.h"
#include "../utils.h"

If::If() : Function(3)
{
}

const Data *If::safeCall(const Context *context, const Arguments &args) const
{
    Arguments::const_iterator it = args.begin();
    const Data *condition = (*it)->invoke(context);
    const Symbol *truthy = *(++it);
    const Symbol *falsey = *(++it);

    return condition->getBoolean()
            ? truthy->invoke(context)
            : falsey->invoke(context);
}
