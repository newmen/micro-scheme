#ifndef SCAVENGER_H
#define SCAVENGER_H

#include <unordered_set>
#include "garbage.h"

class Scavenger
{
    static Scavenger *__instance;

public:
    static Scavenger *instance();
    static void destroy();

private:
    typedef std::unordered_set<const Garbage *> Objects;
    Objects _objects;

    Scavenger() = default;
public:
    ~Scavenger();

    void mark(const Garbage *object);
    void unmark(const Garbage *object);
};

#endif // SCAVENGER_H
