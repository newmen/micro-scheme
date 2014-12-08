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

    virtual const Object *safeCall(const Context *context, const Objects &args) const = 0;
public:
    const Object *call(const Context *context, const Objects &args) const override;

protected:
    void checkArity(const Objects &args) const;
};

#endif // FIXED_ARITY_FUNCTION_H
