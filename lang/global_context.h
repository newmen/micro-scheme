#ifndef GLOBAL_CONTEXT_H
#define GLOBAL_CONTEXT_H

#include "context.h"

class GlobalContext : public Context
{
    static GlobalContext *__instance;

public:
    static GlobalContext *instance();

    std::string inspect() const override;

private:
    GlobalContext() = default;
};

#endif // GLOBAL_CONTEXT_H
