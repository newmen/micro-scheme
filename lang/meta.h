#ifndef META_H
#define META_H

#include "sequence.h"
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
    void checkSequence(const Symbol *symbol) const;
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
    this->checkSequence(args.front());

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
void Meta<F>::checkSequence(const Symbol *symbol) const
{
    const Sequence *sequence = dynamic_cast<const Sequence *>(symbol);
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

#endif // META_H
