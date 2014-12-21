#include "lambda.h"
#include "../statement.h"
#include "../keyword.h"
#include "../user_function.h"

const Data *Lambda::safeCall(const Context *context, const Symbols &args) const
{
    const Symbol *firstArg = args.front();
    checkSignature(firstArg);

    const Statement *signature = dynamic_cast<const Statement *>(firstArg);
    const Keywords funcArgs = toKeywords(signature->symbols());
    const Symbols chunks = cutChunks(args);
    const Symbol *lastArg = args.back();

    return new UserFunction(context, funcArgs, chunks, lastArg);
}
