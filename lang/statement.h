#ifndef STATEMENT_H
#define STATEMENT_H

#include "garbage.h"
#include "data.h"

class Context;

// interface
class Statement : virtual public Garbage
{
protected:
    Statement() = default;

public:
    virtual ~Statement() {}

    virtual const Data *call(const Context *) const = 0;
};

#endif // STATEMENT_H
