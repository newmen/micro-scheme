#include "context.h"

Context::Context(const Context *parent) : _parent(parent)
{
}

std::string Context::inspect() const
{
    return std::string("Context") + Object::inspect();
}

void Context::assign(const std::string &name, const Function *function)
{
    if (_table.find(name) != _table.end())
    {
        throw DuplicationError(name);
    }

    _table[name] = function;
}

const Function *Context::get(const std::string &name) const
{
    Table::const_iterator it = _table.find(name);
    if (it == _table.cend() && !_parent)
    {
        throw UndefinedError(name);
    }
    else if (it == _table.cend())
    {
        return _parent->get(name);
    }
    else
    {
        return it->second;
    }
}
