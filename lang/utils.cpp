#include "utils.h"
#include "symbol.h"
#include "error.h"

const Data *Utils::getData(const Context *context, const Object *object)
{
    const Data *data = dynamic_cast<const Data *>(object);
    if (data)
    {
        return data;
    }

    const Symbol *symbol = dynamic_cast<const Symbol *>(object);
    if (symbol)
    {
        return getData(context, symbol->invoke(context));
    }

    throw Error("Could not convert object to data");
    return nullptr;
}
