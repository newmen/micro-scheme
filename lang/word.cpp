#include "word.h"
#include "error.h"

Word::Word(const std::string &name) : _name(name)
{
}

std::string Word::inspect() const
{
    return _name + Garbage::inspect();
}

const Data *Word::call(const Context *) const
{
    throw Error("Could not get value for non data statement");
    return nullptr;
}

std::string Word::name() const
{
    return _name;
}
