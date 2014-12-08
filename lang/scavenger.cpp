#include "scavenger.h"
#include <assert.h>
#include <iostream>

Scavenger *Scavenger::__instance = nullptr;
Scavenger *Scavenger::instance()
{
    if (!__instance)
    {
        __instance = new Scavenger();
    }

    return __instance;
}

void Scavenger::destroy()
{
    delete __instance;
}

Scavenger::~Scavenger()
{
    while (!_objects.empty())
    {
        delete *_objects.begin();
    }
}

void Scavenger::mark(const Garbage *object)
{
    std::cout << "mark: " << object->inspect() << std::endl;
    Objects::iterator it = _objects.find(object);
    assert(it == _objects.end());

    _objects.insert(object);
}

void Scavenger::unmark(const Garbage *object)
{
    std::cout << "unmark: " << object->inspect() << std::endl;
    Objects::iterator it = _objects.find(object);
    assert(it != _objects.end());

    _objects.erase(it);
}
