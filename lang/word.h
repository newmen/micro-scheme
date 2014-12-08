#ifndef WORD_H
#define WORD_H

#include <string>
#include "statement.h"
#include "context.h"

class Word : public Statement
{
    const std::string _name;

public:
    Word(const std::string &name);

    std::string inspect() const override;
    const Data *call(const Context *) const override;

    std::string name() const;
};

#endif // WORD_H
