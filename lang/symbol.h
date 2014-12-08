#ifndef SYMBOL_H
#define SYMBOL_H

#include "garbage.h"
#include "data.h"

class Context;

// interface
class Symbol : virtual public Garbage
{
protected:
    Symbol() = default;

public:
    virtual ~Symbol() {}

    virtual const Data *call(const Context *) const = 0;
};

#endif // SYMBOL_H
