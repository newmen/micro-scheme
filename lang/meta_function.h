#ifndef META_FUNCTION_H
#define META_FUNCTION_H

#include "fixed_arity_function.h"
#include "keywords.h"

class MetaFunction : public FixedArityFunction
{
protected:
    MetaFunction(unsigned arity);

    Keywords toKeywords(const Objects &objects) const;

public:
    const Object *call(const Context *context, const Objects &args) const override;

private:
    void checkSequence(const Object *object) const;
};

#endif // META_FUNCTION_H
