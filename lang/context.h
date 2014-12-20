#ifndef CONTEXT_H
#define CONTEXT_H

#include "scope.h"

class Context : public Scope
{
    Table _table;

    struct DuplicationError : public Error
    {
        DuplicationError(const std::string &name) :
            Error(std::string("Duplication ") + name) {}
    };

public:
    Context(const Scope *parent = nullptr);

    std::string inspect() const override;

    void assign(const std::string &name, const Function *function);
    Context *wrap(const Context *other) const;

protected:
    const Table &table() const override;

private:
    const Scope *common(const Context *other) const;
    const Scope *append(const Scope *source, const Scope *root, const Scope *target) const;
};

#endif // CONTEXT_H
