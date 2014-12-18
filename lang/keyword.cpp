#include "keyword.h"
#include "function.h"

Keyword::Keyword(const std::string &name) : _name(name)
{
}

std::string Keyword::inspect() const
{
    return _name + Object::inspect();
}

const Data *Keyword::invoke(const Context *context) const
{
    const Function *function = context->get(_name);
    if (function->arity() == 0)
    {
        return function->call(context);
    }
    else
    {
        return function;
    }
}

std::string Keyword::name() const
{
    return _name;
}
