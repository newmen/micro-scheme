#ifndef STATEMENT_H
#define STATEMENT_H

#include <list>
#include "symbol.h"
#include "symbols.h"

class Statement : public Symbol
{
    const Symbols _symbols;

public:
    Statement(const Symbols &args);

    std::string inspect() const override;
    const Data *invoke(const Context *context) const override;

    const Symbols &symbols() const;
    const Symbol *head() const;
    Symbols tail() const;
};

#endif // STATEMENT_H
