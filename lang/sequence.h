#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <list>
#include "symbol.h"
#include "keyword.h"
#include "symbols.h"

class Sequence : public Symbol
{
    const Keyword *_head;
    const Symbols _symbols;

public:
    Sequence(const Keyword *name, const Symbols &args);

    std::string inspect() const override;
    const Data *call(const Context *context) const override;
};

#endif // SEQUENCE_H
