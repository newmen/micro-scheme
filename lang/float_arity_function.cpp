#include "float_arity_function.h"

FloatArityFunction::FloatArityFunction(unsigned minArity) : FixedArityFunction(minArity)
{
}

void FloatArityFunction::checkArity(const Arguments &args) const
{
    unsigned argsNum = args.size();
    if (_arity > argsNum)
    {
        throw ArityError(_arity, argsNum);
    }
}
