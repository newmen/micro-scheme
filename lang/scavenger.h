#ifndef SCAVENGER_H
#define SCAVENGER_H

#include <unordered_set>
#include "object.h"

class Scavenger
{
    static Scavenger *__instance;

public:
    static Scavenger *instance();
    static void destroy();

private:
    typedef std::unordered_set<const Object *> Objects;
    Objects _objects;

    Scavenger() = default;
public:
    ~Scavenger();

    void mark(const Object *object);
    void unmark(const Object *object);
};

#endif // SCAVENGER_H
