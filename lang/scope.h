#ifndef SCOPE_H
#define SCOPE_H

#include <map>
#include <string>
#include "object.h"
#include "error.h"
#include "function.h"

class Context;

// abstract
class Scope : public Object
{
    friend class Context;
    const Scope *const _parent;

    struct UndefinedError : public Error
    {
        UndefinedError(const std::string &name) :
            Error(std::string("Undefined \"") + name + "\" symbol") {}
    };

protected:
    typedef std::map<std::string, const Function *> Table;

    Scope(const Scope *parent = nullptr);

    virtual const Table &table() const = 0;

public:
    const Function *get(const std::string &name) const;
};

#endif // SCOPE_H
