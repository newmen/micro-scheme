#include "meta_function.h"
#include "sequence.h"
#include "keyword.h"

MetaFunction::MetaFunction(unsigned arity) : FixedArityFunction(arity)
{
}

Keywords MetaFunction::toKeywords(const Objects &objects) const
{
    Keywords result;
    for (const Object *symbol : objects)
    {
        const Keyword *keyword = dynamic_cast<const Keyword *>(symbol);
        result.push_back(keyword);
    }

    return result;
}

const Object *MetaFunction::call(const Context *context, const Objects &args) const
{
    checkArity(args);
    checkSequence(args.front());

    return safeCall(context, args);
}

void MetaFunction::checkSequence(const Object *object) const
{
    const Sequence *sequence = dynamic_cast<const Sequence *>(object);
    if (!sequence)
    {
        throw Error("The first argument of define should be a sequence");
    }

    for (const Object *symbol : sequence->symbols())
    {
        const Keyword *keyword = dynamic_cast<const Keyword *>(symbol);
        if (!keyword)
        {
            throw Error("Each argument of define sequence should be a word");
        }
    }
}
