#include "variable.h"

Variable::Variable(const Symbol *body) : Variable(0, body)
{
}

Variable::Variable(unsigned arity, const Symbol *body) :
    Function(arity), _body(body)
{
}

const Data *Variable::safeCall(const Context *context, const Arguments &) const
{
    return _body->invoke(context);
}

const Symbol *Variable::body() const
{
    return _body;
}
