#ifndef FIXED_ARITY_FUNCTION_H
#define FIXED_ARITY_FUNCTION_H

#include "function.h"

// abstract
class FixedArityFunction : public Function
{
protected:
    const unsigned _arity;

private:
    struct ArityError : public Error
    {
        ArityError(unsigned current, unsigned passed) :
            Error(std::string("Wrong number of arguments (") +
                  Utils::toString(passed) + " for " + Utils::toString(current) + ")") {}
    };

protected:
    FixedArityFunction(unsigned arity);

    virtual void checkArity(const Objects &args) const;
    virtual const Object *safeCall(const Context *context, const Objects &args) const = 0;

public:
    const Object *call(const Context *context, const Objects &args) const override;
};

#endif // FIXED_ARITY_FUNCTION_H
