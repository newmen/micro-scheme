#include "user_function.h"

UserFunction::UserFunction(const Context *context, const Keywords &args, const Arguments &intermedBodies, const Symbol *body) :
    Variable(args.size(), body), _externalContext(context), _arguments(args), _intermediateBodies(intermedBodies)
{
}

const Data *UserFunction::safeCall(const Context *context, const Arguments &args) const
{
    if (arity() == 0)
    {
        return body()->invoke(context);
    }
    else
    {
        Context *subContext = _externalContext->wrap(context);
        invokeIntermediateBodies(subContext);
        assignArgumentsTo(subContext, args);

        return body()->invoke(subContext);
    }
}

void UserFunction::invokeIntermediateBodies(Context *context) const
{
    for (const Symbol *symbol : _intermediateBodies)
    {
        symbol->invoke(context);
    }
}

void UserFunction::assignArgumentsTo(Context *context, const Arguments &args) const
{
    Keywords::const_iterator ik = _arguments.begin();
    Arguments::const_iterator ia = args.begin();
    for (; ik != _arguments.end(); ik++, ia++)
    {
        const Data *data = (*ia)->invoke(context);
        const Function *function = dynamic_cast<const Function *>(data);
        if (!function)
        {
            function = new Variable(data);
        }

        context->assign((*ik)->name(), function);
    }
}
