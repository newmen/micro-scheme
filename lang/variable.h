#ifndef VARIABLE_H
#define VARIABLE_H

#include "function.h"

class Variable : public Function
{
    const Symbol *const _body;

public:
    Variable(const Symbol *body);

protected:
    Variable(unsigned arity, const Symbol *body);

    const Data *safeCall(const Context * context, const Arguments &) const;
    const Symbol *body() const;
};

#endif // VARIABLE_H
