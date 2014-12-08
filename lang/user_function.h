#ifndef USER_FUNCTION_H
#define USER_FUNCTION_H

#include "fixed_arity_function.h"
#include "keywords.h"

class UserFunction : public FixedArityFunction
{
    const Keywords _args;
    const Object *_body;

    UserFunction(const Object *body);
public:
    UserFunction(const Keywords &args, const Object *body);

private:
    const Object *safeCall(const Context * context, const Objects &args) const;
};

#endif // USER_FUNCTION_H
