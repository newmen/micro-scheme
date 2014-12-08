#ifndef CONTEXT_H
#define CONTEXT_H

#include <unordered_map>
#include <string>
#include "garbage.h"
#include "error.h"
#include "function.h"

class Context : virtual public Garbage
{
protected:
    typedef std::unordered_map<std::string, const Function *> Table;

private:
    Table _table;
    Context *_parent;

public:
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

    Context(Context *parent = nullptr);
    virtual ~Context() {}

    std::string inspect() const override;

    void assign(const std::string &name, const Function *function);
    const Function *get(const std::string &name) const;
};

#endif // CONTEXT_H
