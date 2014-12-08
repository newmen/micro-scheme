#include "function.h"
#include "global_context.h"

Function::Function() : Function(GlobalContext::instance())
{
}

Function::Function(Context *context) : _context(context)
{
}

std::string Function::inspect() const
{
    return std::string("Function") + Object::inspect();
}

const Context *Function::context() const
{
    return _context;
}
