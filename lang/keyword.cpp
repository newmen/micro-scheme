#include "keyword.h"
#include "error.h"

Keyword::Keyword(const std::string &name) : _name(name)
{
}

std::string Keyword::inspect() const
{
    return _name + Object::inspect();
}

const Object *Keyword::invoke(const Context *context) const
{
    return context->get(_name)->call(context);
}

std::string Keyword::name() const
{
    return _name;
}
