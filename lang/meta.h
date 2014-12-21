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

public:
    const Data *call(const Context *context, const Symbols &args) const override;

protected:
    Keywords toKeywords(const Symbols &symbols) const;

private:
    void checkStatement(const Symbol *symbol) const;
};

///////////////////////////////////////////////////////////////////////////////

template <class F>
Meta<F>::Meta(unsigned arity) : F(arity)
{
}

template <class F>
const Data *Meta<F>::call(const Context *context, const Symbols &args) const
{
    this->checkArity(args);
    this->checkStatement(args.front());

    return this->safeCall(context, args);
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
void Meta<F>::checkStatement(const Symbol *symbol) const
{
    const Statement *statement = dynamic_cast<const Statement *>(symbol);
    if (!statement)
    {
        throw Error("The first argument of define should be a statement");
    }

    for (const Object *symbol : statement->symbols())
    {
        const Keyword *keyword = dynamic_cast<const Keyword *>(symbol);
        if (!keyword)
        {
            throw Error("Each argument of first define statement should be a word");
        }
    }
}

#endif // META_H
