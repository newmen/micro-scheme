#include "user_function.h"
#include <assert.h>

UserFunction::UserFunction(const Object *body) :
    UserFunction(Keywords(), body)
{
}

UserFunction::UserFunction(const Keywords &args, const Object *body) :
    FixedArityFunction(args.size()), _args(args), _body(body)
{
}

const Object *UserFunction::safeCall(const Context *context, const Objects &args) const
{
    Context *subContext = new Context(context);
    Keywords::const_iterator ik = _args.begin();
    Objects::const_iterator ia = args.begin();
    for (; ik != _args.end(); ik++, ia++)
    {
        const Function *function = dynamic_cast<const Function *>(*ia);
        if (!function)
        {
            const Symbol *symbol = dynamic_cast<const Symbol *>(*ia);
            if (symbol)
            {
                function = new UserFunction(symbol->invoke(subContext));
            }
            else
            {
                function = new UserFunction(*ia);
            }
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
        const Symbol *symbol = dynamic_cast<const Symbol *>(_body);
        if (symbol)
        {
            return symbol->invoke(subContext);
        }
        else
        {
            return _body;
        }
    }
}
