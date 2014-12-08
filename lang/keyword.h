#ifndef KEYWORD_H
#define KEYWORD_H

#include <string>
#include "symbol.h"
#include "context.h"

class Keyword : public Symbol
{
    const std::string _name;

public:
    Keyword(const std::string &name);

    std::string inspect() const override;
    const Object *invoke(const Context *context) const override;

    std::string name() const;
};

#endif // KEYWORD_H
