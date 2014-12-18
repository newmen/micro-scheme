#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include "data.h"
#include "arguments.h"
#include "error.h"
#include "utils.h"

class Context;

// interface
class Function : public Data
{
    const unsigned _arity;

    struct ArityError : public Error
    {
        ArityError(unsigned current, unsigned passed) :
            Error(std::string("Wrong number of arguments (") +
                  Utils::toString(passed) + " for " + Utils::toString(current) + ")") {}
    };

protected:
    Function(unsigned arity);

    virtual void checkArity(const Arguments &args) const;
    virtual const Data *safeCall(const Context *context, const Arguments &args) const = 0;

public:
    std::string inspect() const override;
    std::string value() const override;
    bool eql(const Data *other) const override;

    virtual const Data *call(const Context *context, const Arguments &args) const;
    const Data *call(const Context *context) const;

    unsigned arity() const;
};

#endif // FUNCTION_H
