#include "define.h"
#include <sstream>
#include "../statement.h"
#include "../keyword.h"
#include "../user_function.h"
#include "../ok.h"

Define::Define() : Meta(2)
{
}

const Data *Define::safeCall(const Context *context, const Symbols &args) const
{
    Keywords funcArgs;
    Symbols::const_iterator arg = args.begin();
    const Keyword *funcName = dynamic_cast<const Keyword *>(*arg);
    if (!funcName)
    {
        checkSignature(*arg);

        const Statement *signature = dynamic_cast<const Statement *>(*arg);
        funcName = dynamic_cast<const Keyword *>(signature->head());
        funcArgs = toKeywords(signature->tail());
    }

    std::advance(arg, 1);
    Symbols chunks(arg, args.cend());
    const Symbol *last = chunks.back();
    chunks.pop_back();

    unsigned i = 1;
    for (const Symbol *symbol : chunks)
    {
        const Statement *statement = dynamic_cast<const Statement *>(symbol);
        if (statement)
        {
            ++i;
        }
        else
        {
            std::stringstream ss;
            ss << "One of intermediate define function body argument ("
               << i << " of " << (args.size() - 1)
               << ") is not a statement";
            throw Error(ss.str());
        }
    }

    const Function *function = new UserFunction(context, funcArgs, chunks, last);
    Context *changingContext = const_cast<Context *>(context);
    changingContext->assign(funcName->name(), function);

    return Ok::instance();
}
