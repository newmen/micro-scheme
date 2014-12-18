#ifndef SCAVENGER_H
#define SCAVENGER_H

#include <unordered_set>
#include "tools/singleton.h"
#include "object.h"

class Scavenger : public Singleton<Scavenger>
{
    typedef std::unordered_set<const Object *> Objects;
    Objects _objects;

    friend class Singleton;
    Scavenger() = default;

public:
    ~Scavenger();

    static void destroy();

    void mark(const Object *object);
    void unmark(const Object *object);
};

#endif // SCAVENGER_H
