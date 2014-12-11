#ifndef SYMBOL_H
#define SYMBOL_H

#include "object.h"

class Context;
class Data;

// interface
class Symbol : public Object
{
protected:
    Symbol() = default;

public:
    virtual const Data *invoke(const Context *context) const = 0;
};

#endif // SYMBOL_H
