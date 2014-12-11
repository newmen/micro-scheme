#include "user_function.h"

UserFunction::UserFunction(const Symbol *body) :
    UserFunction(Keywords(), body)
{
}

UserFunction::UserFunction(const Keywords &args, const Symbol *body, const Arguments &intermedBodies) :
    FixedArityFunction(args.size()), _args(args), _intermedBodies(intermedBodies), _body(body)
{
}

const Data *UserFunction::safeCall(const Context *context, const Arguments &args) const
{
    Context *subContext = new Context(context);
    for (const Symbol *symbol : _intermedBodies)
    {
        symbol->invoke(subContext);
    }

    Keywords::const_iterator ik = _args.begin();
    Arguments::const_iterator ia = args.begin();
    for (; ik != _args.end(); ik++, ia++)
    {
        const Data *data = (*ia)->invoke(subContext);
        const Function *function = dynamic_cast<const Function *>(data);
        if (!function)
        {
            function = new UserFunction(data);
        }

        subContext->assign((*ik)->name(), function);
    }

    const Function *body = dynamic_cast<const Function *>(_body);
    if (body)
    {
        // TODO: the body function must be partialy applied
        return nullptr;
    }
    else
    {
        return _body->invoke(subContext);
    }
}
