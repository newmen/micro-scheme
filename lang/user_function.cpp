#include "user_function.h"

UserFunction::UserFunction(const Context *context, const Keywords &args, const Symbols &intermedBodies, const Symbol *body) :
    Variable(args.size(), body), _externalContext(context), _arguments(args), _intermediateBodies(intermedBodies)
{
}

const Data *UserFunction::safeCall(const Context *context, const Symbols &args) const
{
    if (arity() == 0)
    {
        return body()->invoke(context);
    }
    else
    {
        Context *subContext = _externalContext->wrap(context);
        assignArgumentsTo(subContext, context, args);
        invokeIntermediateBodies(subContext);
        return body()->invoke(subContext);
    }
}

void UserFunction::assignArgumentsTo(Context *subContext, const Context *extContext, const Symbols &args) const
{
    Keywords::const_iterator ik = _arguments.begin();
    Symbols::const_iterator ia = args.begin();
    for (; ik != _arguments.end(); ik++, ia++)
    {
        const Data *data = (*ia)->invoke(extContext);
        const Function *function = dynamic_cast<const Function *>(data);
        if (!function)
        {
            function = new Variable(data);
        }

        subContext->assign((*ik)->name(), function);
    }
}

void UserFunction::invokeIntermediateBodies(Context *context) const
{
    for (const Symbol *symbol : _intermediateBodies)
    {
        symbol->invoke(context);
    }
}
