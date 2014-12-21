#ifndef META_H
#define META_H

#include "statement.h"
#include "keyword.h"
#include "keywords.h"

// function role
template <class F>
class Meta : public F
{
protected:
    Meta(unsigned arity);

    Keywords toKeywords(const Symbols &symbols) const;
    void checkSignature(const Symbol *symbol) const;
};

///////////////////////////////////////////////////////////////////////////////

template <class F>
Meta<F>::Meta(unsigned arity) : F(arity)
{
}

template <class F>
Keywords Meta<F>::toKeywords(const Symbols &symbols) const
{
    Keywords result;
    for (const Object *symbol : symbols)
    {
        const Keyword *keyword = dynamic_cast<const Keyword *>(symbol);
        result.push_back(keyword);
    }

    return result;
}

template <class F>
void Meta<F>::checkSignature(const Symbol *symbol) const
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

#endif // META_H
