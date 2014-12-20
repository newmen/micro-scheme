#include "float_arity_function.h"

FloatArityFunction::FloatArityFunction(unsigned minArity) : Function(minArity)
{
}

void FloatArityFunction::checkArity(const Symbols &args) const
{
    unsigned argsNum = args.size();
    if (arity() > argsNum)
    {
        throw MinArityError(arity(), argsNum);
    }
}
