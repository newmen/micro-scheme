#include "define.h"
#include <sstream>
#include "../sequence.h"
#include "../keyword.h"
#include "../user_function.h"

Define::Define() : Meta(2)
{
}

const Object *Define::safeCall(const Context *context, const Objects &args) const
{
    Objects chunks(args);
    const Sequence *signature = dynamic_cast<const Sequence *>(chunks.front());
    chunks.pop_front();

    const Keyword *funcName = dynamic_cast<const Keyword *>(signature->head());
    Keywords funcArgs = toKeywords(signature->tail());

    const Object *last = chunks.back();
    chunks.pop_back();

    unsigned i = 1;
    for (const Object *object : chunks)
    {
        const Sequence *sequence = dynamic_cast<const Sequence *>(object);
        if (sequence)
        {
            ++i;
        }
        else
        {
            std::stringstream ss;
            ss << "The argument of define body ("
               << i << " of " << (args.size() - 1)
               << ") is not a sequence";
            throw Error(ss.str());
        }
    }

    const Function *function = new UserFunction(funcArgs, last, chunks);
    Context *changingContext = const_cast<Context *>(context);
    changingContext->assign(funcName->name(), function);

    return function;
}
