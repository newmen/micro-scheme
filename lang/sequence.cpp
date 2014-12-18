#include "sequence.h"
#include <sstream>
#include "context.h"
#include "keyword.h"
#include "function.h"
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
    const Data *key = head()->invoke(context);
    const Sequence *sequence = dynamic_cast<const Sequence *>(key);
    if (sequence)
    {
        key = sequence->invoke(context);
    }

    const Function *function = dynamic_cast<const Function *>(key);
    if (!function)
    {
        std::stringstream ss;
        ss << key->value() << " is not a function";
        throw Error(ss.str());
    }

    return function->call(context, tail());
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
