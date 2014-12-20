#ifndef USER_FUNCTION_H
#define USER_FUNCTION_H

#include "variable.h"
#include "keywords.h"

class UserFunction : public Variable
{
    const Context *const _externalContext;
    const Keywords _arguments;
    const Symbols _intermediateBodies;

public:
    UserFunction(const Context *context, const Keywords &args, const Symbols &intermedBodies, const Symbol *body);

protected:
    const Data *safeCall(const Context *context, const Symbols &args) const;

private:
    void invokeIntermediateBodies(Context *context) const;
    void assignArgumentsTo(Context *context, const Symbols &args) const;
};

#endif // USER_FUNCTION_H
