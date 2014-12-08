#include "sequence.h"
#include <sstream>
#include "context.h"
#include "keyword.h"

Sequence::Sequence(const Arguments &args) : _symbols(args)
{
}

std::string Sequence::inspect() const
{
    std::stringstream ss;
    bool isFirst = true;
    ss << "(";
    for (const Object *s : _symbols)
    {
        if (isFirst)
        {
            isFirst = false;
        }
        else
        {
            ss << " ";
        }
        ss << s->inspect();
    }
    ss << ")";

    return ss.str() + Object::inspect();
}

const Object *Sequence::invoke(const Context *context) const
{
    Arguments args(_symbols);
    const Object *first = args.front();
    args.pop_front();

    const Keyword *key = dynamic_cast<const Keyword *>(first);
    if (!key)
    {
        throw Error("First item of sequence doesn't a keyword");
    }

    return context->get(key->name())->call(args);
}
