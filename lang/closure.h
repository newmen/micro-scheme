#ifndef CLOSURE_H
#define CLOSURE_H

#include "scope.h"

class Closure : public Scope
{
    const Table &_table;

public:
    Closure(const Scope *parent, const Table &table);

    std::string inspect() const override;
    const Table &table() const override;
};

#endif // CLOSURE_H
