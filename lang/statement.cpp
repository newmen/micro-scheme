#include "statement.h"
#include <sstream>
#include "context.h"
#include "keyword.h"
#include "function.h"
#include "error.h"

Statement::Statement(const Symbols &args) : _symbols(args)
{
}

std::string Statement::inspect() const
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

const Data *Statement::invoke(const Context *context) const
{
    const Data *key = head()->invoke(context);
    const Statement *statement = dynamic_cast<const Statement *>(key);
    if (statement)
    {
        key = statement->invoke(context);
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

const Symbols &Statement::symbols() const
{
    return _symbols;
}

const Symbol *Statement::head() const
{
    return _symbols.front();
}

Symbols Statement::tail() const
{
    Symbols result(_symbols);
    result.pop_front();
    return result;
}
