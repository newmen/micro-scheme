#ifndef KEYWORD_H
#define KEYWORD_H

#include <string>
#include "statement.h"
#include "context.h"

class Keyword : public Statement
{
    const std::string _name;

public:
    Keyword(const std::string &name);

    std::string inspect() const override;
    const Data *call(const Context *) const override;

    std::string name() const;
};

#endif // KEYWORD_H
