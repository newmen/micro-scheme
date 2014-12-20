#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <list>
#include "symbol.h"
#include "symbols.h"

class Sequence : public Symbol
{
    const Symbols _symbols;

public:
    Sequence(const Symbols &args);

    std::string inspect() const override;
    const Data *invoke(const Context *context) const override;

    const Symbols &symbols() const;
    const Symbol *head() const;
    Symbols tail() const;
};

#endif // SEQUENCE_H
