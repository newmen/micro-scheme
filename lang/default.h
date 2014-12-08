#ifndef DEFAULT_H
#define DEFAULT_H

#include "object.h"
#include "data.h"
#include "symbol.h"

// function role
template <class B>
class Default : public B
{
protected:
    template <class... Args>
    Default(Args... args) : B(args...) {}

    const Data *getData(const Object *object) const;
};

///////////////////////////////////////////////////////////////////////////////

template <class B>
const Data *Default<B>::getData(const Object *object) const
{
    const Data *data = dynamic_cast<const Data *>(object);
    if (data)
    {
        return data;
    }

    const Symbol *symbol = dynamic_cast<const Symbol *>(object);
    if (symbol)
    {
        return getData(symbol->invoke(this->context()));
    }

    throw Error("Could not convert object to data");
    return nullptr;
}

#endif // DEFAULT_H
