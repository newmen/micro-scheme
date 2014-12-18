#include "sequence.h"
#include <sstream>
#include "context.h"
#include "keyword.h"
#include "error.h"

Sequence::Sequence(const Arguments &args) : _symbols(args)
{
}

std::string Sequence::inspect() const
{
    std::stringstream ss;
    ss << "(" << head()->inspect();
    for (const Object *s : tail())
    {
        ss << " " << s->inspect();
    }
    ss << ")";

    return ss.str() + Object::inspect();
}

const Data *Sequence::invoke(const Context *context) const
{
    const Keyword *key = dynamic_cast<const Keyword *>(head());
    if (!key)
    {
        throw Error("First item of sequence is not a keyword");
    }

    return context->get(key->name())->call(context, tail());
}

const Arguments &Sequence::symbols() const
{
    return _symbols;
}

const Symbol *Sequence::head() const
{
    return _symbols.front();
}

Arguments Sequence::tail() const
{
    Arguments result(_symbols);
    result.pop_front();
    return result;
}
