#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include "object.h"
#include "objects.h"
#include "error.h"
#include "utils.h"

class Context;

// interface
class Function : virtual public Object
{
protected:
    Function() = default;

public:
    virtual ~Function() {}

    std::string inspect() const override;

    const Object *call(const Context *context) const;
    virtual const Object *call(const Context *context, const Objects &args) const = 0;
};

#endif // FUNCTION_H
