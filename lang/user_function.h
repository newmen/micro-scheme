#ifndef USER_FUNCTION_H
#define USER_FUNCTION_H

#include "variable.h"
#include "keywords.h"

class UserFunction : public Variable
{
    const Context *const _externalContext;
    const Keywords _arguments;
    const Arguments _intermediateBodies;

public:
    UserFunction(const Context *context, const Keywords &args, const Arguments &intermedBodies, const Symbol *body);

protected:
    const Data *safeCall(const Context *context, const Arguments &args) const;

private:
    void invokeIntermediateBodies(Context *context) const;
    void assignArgumentsTo(Context *context, const Arguments &args) const;
};

#endif // USER_FUNCTION_H
