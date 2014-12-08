#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <list>
#include "symbol.h"
#include "objects.h"

class Sequence : public Symbol
{
    const Objects _symbols;

public:
    Sequence(const Objects &args);

    std::string inspect() const override;
    const Object *invoke(const Context *context) const override;

    const Objects &symbols() const;
    const Object *head() const;
    Objects tail() const;
};

#endif // SEQUENCE_H
