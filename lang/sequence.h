#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <list>
#include "statement.h"
#include "keyword.h"
#include "statements.h"

class Sequence : public Statement
{
    const Keyword *_head;
    const Statements _statements;

public:
    Sequence(const Keyword *name, const Statements &args);

    std::string inspect() const override;
    const Data *call(const Context *context) const override;
};

#endif // SEQUENCE_H
