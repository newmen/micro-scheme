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
protected:
    Function() = default;

public:
    std::string inspect() const override;
    std::string value() const override;

    const Data *call(const Context *context) const;
    virtual const Data *call(const Context *context, const Arguments &args) const = 0;
};

#endif // FUNCTION_H
