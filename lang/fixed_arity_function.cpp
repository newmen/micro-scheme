#include "fixed_arity_function.h"

FixedArityFunction::FixedArityFunction(unsigned arity) : _arity(arity)
{
}

FixedArityFunction::FixedArityFunction(Context *context, unsigned arity) :
    Function(context), _arity(arity)
{
}

void FixedArityFunction::checkArity(const Arguments &args) const
{
    unsigned argsNum = args.size();
    if (_arity != argsNum)
    {
        throw ArityError(_arity, argsNum);
    }
}
