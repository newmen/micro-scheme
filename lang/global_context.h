#ifndef GLOBAL_CONTEXT_H
#define GLOBAL_CONTEXT_H

#include "tools/singleton.h"
#include "context.h"

class GlobalContext : public Singleton<GlobalContext, Context>
{
    friend class Singleton;
    GlobalContext() = default;

public:
    static GlobalContext *instance();

    std::string inspect() const override;
};

#endif // GLOBAL_CONTEXT_H
