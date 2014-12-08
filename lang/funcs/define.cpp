#include "define.h"
#include "../sequence.h"
#include "../keyword.h"
#include "../user_function.h"

Define::Define() : MetaFunction(2)
{
}

const Object *Define::safeCall(const Context *context, const Objects &args) const
{
    const Sequence *signature = dynamic_cast<const Sequence *>(args.front());
    const Keyword *funcName = dynamic_cast<const Keyword *>(signature->head());
    Keywords funcArgs = toKeywords(signature->tail());

    const Function *function = new UserFunction(funcArgs, args.back());

    Context *changingContext = const_cast<Context *>(context);
    changingContext->assign(funcName->name(), function);

    return function;
}
