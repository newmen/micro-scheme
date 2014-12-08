#ifndef SYMBOL_H
#define SYMBOL_H

#include "object.h"
#include "data.h"

class Context;

// interface
class Symbol : virtual public Object
{
protected:
    Symbol() = default;

public:
    virtual ~Symbol() {}

    virtual const Object *invoke(const Context *) const = 0;
};

#endif // SYMBOL_H
