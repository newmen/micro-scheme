#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <list>
#include "symbol.h"
#include "arguments.h"

class Sequence : public Symbol
{
    const Arguments _symbols;

public:
    Sequence(const Arguments &args);

    std::string inspect() const override;
    const Data *invoke(const Context *context) const override;

    const Arguments &symbols() const;
    const Symbol *head() const;
    Arguments tail() const;
};

#endif // SEQUENCE_H
