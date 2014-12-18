#ifndef USER_FUNCTION_H
#define USER_FUNCTION_H

#include "function.h"
#include "keywords.h"

class UserFunction : public Function
{
    const Keywords _args;
    const Arguments _intermedBodies;
    const Symbol *_body;

    UserFunction(const Symbol *body);
public:
    UserFunction(const Keywords &args, const Symbol *body, const Arguments &intermedBodies = Arguments());

private:
    const Data *safeCall(const Context * context, const Arguments &args) const;
};

#endif // USER_FUNCTION_H
