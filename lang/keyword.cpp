#include "keyword.h"
#include "error.h"

Keyword::Keyword(const std::string &name) : _name(name)
{
}

std::string Keyword::inspect() const
{
    return _name + Garbage::inspect();
}

const Data *Keyword::call(const Context *) const
{
    throw Error("Could not get value for non data symbol");
    return nullptr;
}

std::string Keyword::name() const
{
    return _name;
}
