#include "sequence.h"
#include <sstream>
#include "arguments.h"
#include "context.h"
#include "utils.h"

Sequence::Sequence(const Keyword *name, const Statements &args) : _head(name), _statements(args)
{
}

std::string Sequence::inspect() const
{
    std::stringstream ss;
    ss << "(" << _head->inspect();
    for (const Statement *s : _statements)
    {
        ss << " " << s->inspect();
    }
    ss << ")";

    return ss.str() + Garbage::inspect();
}

const Data *Sequence::call(const Context *context) const
{
    Arguments args;
    for (const Statement *s : _statements)
    {
        args.push_back(s->call(context));
    }

    return context->get(_head->name())->call(args);
}
