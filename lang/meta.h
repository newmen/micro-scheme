#ifndef META_H
#define META_H

#include "fixed_arity_function.h"
#include "sequence.h"
#include "keyword.h"
#include "keywords.h"

// function role
template <class F>
class Meta : public F
{
protected:
    Meta(unsigned arity);

    Keywords toKeywords(const Objects &objects) const;

public:
    const Object *call(const Context *context, const Objects &args) const override;

private:
    void checkSequence(const Object *object) const;
};

///////////////////////////////////////////////////////////////////////////////

template <class F>
Meta<F>::Meta(unsigned arity) : F(arity)
{
}

template <class F>
Keywords Meta<F>::toKeywords(const Objects &objects) const
{
    Keywords result;
    for (const Object *symbol : objects)
    {
        const Keyword *keyword = dynamic_cast<const Keyword *>(symbol);
        result.push_back(keyword);
    }

    return result;
}

template <class F>
const Object *Meta<F>::call(const Context *context, const Objects &args) const
{
    this->checkArity(args);
    this->checkSequence(args.front());

    return this->safeCall(context, args);
}

template <class F>
void Meta<F>::checkSequence(const Object *object) const
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

#endif // META_H
