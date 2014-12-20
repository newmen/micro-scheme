#include "closure.h"

Closure::Closure(const Scope *parent, const Table &table) :
    Scope(parent), _table(table)
{
}

std::string Closure::inspect() const
{
    return std::string("Closure") + Object::inspect();
}

const Scope::Table &Closure::table() const
{
    return _table;
}
