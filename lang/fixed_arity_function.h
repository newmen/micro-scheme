#ifndef FIXED_ARITY_FUNCTION_H
#define FIXED_ARITY_FUNCTION_H

#include "function.h"

// interface
class FixedArityFunction : public Function
{
    unsigned _arity;

    struct ArityError : public Error
    {
        ArityError(unsigned current, unsigned passed) :
            Error(std::string("Wrong number of arguments (") +
                  Utils::toString(passed) + " for " + Utils::toString(current) + ")") {}
    };

protected:
    FixedArityFunction(unsigned arity);
    FixedArityFunction(Context *context, unsigned arity);

    void checkArity(const Arguments &args) const;
};

#endif // FIXED_ARITY_FUNCTION_H
