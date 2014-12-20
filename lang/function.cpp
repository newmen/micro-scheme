#include "function.h"

Function::Function(unsigned arity) : _arity(arity)
{
}

void Function::checkArity(const Symbols &args) const
{
    unsigned argsNum = args.size();
    if (arity() != argsNum)
    {
        throw ArityError(arity(), argsNum);
    }
}

std::string Function::inspect() const
{
    return std::string("Function") + Object::inspect();
}

std::string Function::value() const
{
    return "function";
}

bool Function::eql(const Data *other) const
{
    return this == other;
}

const Data *Function::call(const Context *context, const Symbols &args) const
{
    checkArity(args);
    return safeCall(context, args);
}

const Data *Function::call(const Context *context) const
{
    return call(context, Symbols());
}

unsigned Function::arity() const
{
    return _arity;
}
