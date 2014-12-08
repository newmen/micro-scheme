#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include "object.h"
#include "arguments.h"
#include "error.h"
#include "utils.h"

class Context;

// interface
class Function : virtual public Object
{
    Context *_context;

protected:
    Function();
    Function(Context *context);

public:
    virtual ~Function() {}

    std::string inspect() const override;
    virtual const Object *call(const Arguments &args) const = 0;

protected:
    const Context *context() const;
};

#endif // FUNCTION_H
