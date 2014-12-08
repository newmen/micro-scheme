#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include "garbage.h"
#include "arguments.h"
#include "error.h"
#include "utils.h"

// interface
class Function : virtual public Garbage
{
protected:
    Function() = default;

public:
    virtual ~Function() {}

    std::string inspect() const override;
    virtual const Data *call(const Arguments &args) const = 0;
};

///////////////////////////////////////////////////////////////////////////////

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
    FixedArityFunction(unsigned arity) : _arity(arity) {}

    void checkArity(const Arguments &args) const
    {
        unsigned argsNum = args.size();
        if (_arity != argsNum)
        {
            throw ArityError(_arity, argsNum);
        }
    }
};

#endif // FUNCTION_H
