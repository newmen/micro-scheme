#include "context.h"
#include "closure.h"

Context::Context(const Scope *parent) : Scope(parent)
{
}

std::string Context::inspect() const
{
    return std::string("Context") + Object::inspect();
}

const Context::Table &Context::table() const
{
    return _table;
}

void Context::assign(const std::string &name, const Function *function)
{
    if (_table.find(name) != _table.end())
    {
        throw DuplicationError(name);
    }

    _table[name] = function;
}

Context *Context::wrap(const Context *other) const
{
    const Scope *root = common(other);
    const Scope *internal = append(other, root);
    const Scope *external = append(this, root, internal);
    return new Context(external);
}

const Scope *Context::common(const Context *other) const
{
    const Scope *result = other;
    const Scope *x = this;

    while (result != x)
    {
        x = x->_parent;
        if (!x)
        {
            result = result->_parent;
            x = this;
        }
    }

    return result;
}

const Scope *Context::append(const Scope *source, const Scope *root, const Scope *target) const
{
    if (root == source)
    {
        return target ? target : root;
    }
    else
    {
        return new Closure(append(source->_parent, root, target), source->table());
    }
}
