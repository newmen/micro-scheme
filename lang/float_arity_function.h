#ifndef FLOAT_ARITY_FUNCTION_H
#define FLOAT_ARITY_FUNCTION_H

#include "function.h"

// abstract
class FloatArityFunction : public Function
{
    struct ArityError : public Error
    {
        ArityError(unsigned current, unsigned passed) :
            Error(std::string("Wrong minimum number of arguments (") +
                  Utils::toString(passed) + " for " + Utils::toString(current) + "...)") {}
    };

protected:
    FloatArityFunction(unsigned minArity);

    void checkArity(const Arguments &args) const override;
};

#endif // FLOAT_ARITY_FUNCTION_H
