#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <list>
#include "symbol.h"
#include "arguments.h"
#include "error.h"

class Sequence : public Symbol
{
    const Arguments _symbols;

public:
    Sequence(const Arguments &args);

    std::string inspect() const override;
    const Object *invoke(const Context *context) const override;
};

#endif // SEQUENCE_H
