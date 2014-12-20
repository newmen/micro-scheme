#include "scope.h"
#include "closure.h"

Scope::Scope(const Scope *parent) : _parent(parent)
{
}

const Function *Scope::get(const std::string &name) const
{
    Table::const_iterator it = table().find(name);
    bool found = it == table().cend();
    if (found && !_parent)
    {
        throw UndefinedError(name);
    }
    else if (found)
    {
        return _parent->get(name);
    }
    else
    {
        return it->second;
    }
}
