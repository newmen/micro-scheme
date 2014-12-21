#include "meta_function.h"
#include <sstream>
#include "statement.h"

MetaFunction::MetaFunction() : FloatArityFunction(2)
{
}

Keywords MetaFunction::toKeywords(const Symbols &symbols) const
{
    Keywords result;
    for (const Object *symbol : symbols)
    {
        const Keyword *keyword = dynamic_cast<const Keyword *>(symbol);
        result.push_back(keyword);
    }

    return result;
}

void MetaFunction::checkSignature(const Symbol *symbol) const
{
    const Statement *statement = dynamic_cast<const Statement *>(symbol);
    if (!statement)
    {
        throw Error("The signature is not a statement");
    }

    for (const Object *symbol : statement->symbols())
    {
        const Keyword *keyword = dynamic_cast<const Keyword *>(symbol);
        if (!keyword)
        {
            throw Error("Each argument of signature statement should be a word");
        }
    }
}

Symbols MetaFunction::cutChunks(const Symbols &args) const
{
    Symbols::const_iterator begin = args.cbegin();
    Symbols::const_iterator end = args.cend();

    std::advance(begin, 1);
    std::advance(end, -1);

    Symbols chunks(begin, end);
    checkChunks(chunks);

    return chunks;
}

void MetaFunction::checkChunks(const Symbols &symbols) const
{
    unsigned i = 1;
    for (const Symbol *symbol : symbols)
    {
        if (dynamic_cast<const Statement *>(symbol))
        {
            ++i;
        }
        else
        {
            std::stringstream ss;
            ss << "One of intermediate body argument ("
               << i << " of " << (symbols.size() - 1)
               << ") is not a statement";
            throw Error(ss.str());
        }
    }
}
