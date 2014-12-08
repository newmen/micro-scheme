#ifndef CONTEXT_H
#define CONTEXT_H

#include <unordered_map>
#include <string>
#include "object.h"
#include "error.h"
#include "function.h"

class Context : virtual public Object
{
    typedef std::unordered_map<std::string, const Function *> Table;

    Table _table;
    const Context *_parent;

    struct DuplicationError : public Error
    {
        DuplicationError(const std::string &name) :
            Error(std::string("Duplication ") + name) {}
    };

    struct UndefinedError : public Error
    {
        UndefinedError(const std::string &name) :
            Error(std::string("Undefined ") + name + " symbol") {}
    };

public:
    Context(const Context *parent = nullptr);
    virtual ~Context() {}

    std::string inspect() const override;

    void assign(const std::string &name, const Function *function);
    const Function *get(const std::string &name) const;
};

#endif // CONTEXT_H
