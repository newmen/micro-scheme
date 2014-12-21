#include "define.h"
#include "../statement.h"
#include "../keyword.h"
#include "../user_function.h"
#include "../ok.h"

const Data *Define::safeCall(const Context *context, const Symbols &args) const
{
    Keywords funcArgs;
    const Symbol *firstArg = args.front();
    const Keyword *funcName = dynamic_cast<const Keyword *>(firstArg);
    if (!funcName)
    {
        checkSignature(firstArg);

        const Statement *signature = dynamic_cast<const Statement *>(firstArg);
        funcName = dynamic_cast<const Keyword *>(signature->head());
        funcArgs = toKeywords(signature->tail());
    }

    const Symbols chunks = cutChunks(args);
    const Symbol *lastArg = args.back();

    const Function *function = new UserFunction(context, funcArgs, chunks, lastArg);
    Context *changingContext = const_cast<Context *>(context);
    changingContext->assign(funcName->name(), function);

    return Ok::instance();
}
