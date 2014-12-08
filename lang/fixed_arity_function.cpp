#include "fixed_arity_function.h"

FixedArityFunction::FixedArityFunction(unsigned arity) : _arity(arity)
{
}

const Object *FixedArityFunction::call(const Context *context, const Objects &args) const
{
    checkArity(args);
    return safeCall(context, args);
}

void FixedArityFunction::checkArity(const Objects &args) const
{
    unsigned argsNum = args.size();
    if (_arity != argsNum)
    {
        throw ArityError(_arity, argsNum);
    }
}
