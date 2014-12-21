#ifndef META_FUNCTION_H
#define META_FUNCTION_H

#include "float_arity_function.h"
#include "symbols.h"
#include "keyword.h"
#include "keywords.h"

class MetaFunction : public FloatArityFunction
{
protected:
    MetaFunction();

    void checkSignature(const Symbol *symbol) const;
    Keywords toKeywords(const Symbols &symbols) const;
    Symbols cutChunks(const Symbols &args) const;

private:
    void checkChunks(const Symbols &symbols) const;
};

#endif // META_FUNCTION_H
