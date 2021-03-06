#include "scavenger.h"
#include <assert.h>
//#include <iostream>

void Scavenger::destroy()
{
    delete instance();
}

Scavenger::~Scavenger()
{
    while (!_objects.empty())
    {
        delete *_objects.begin();
    }
}

void Scavenger::mark(const Object *object)
{
//    std::cout << "mark: " << object->inspect() << std::endl;
    Objects::iterator it = _objects.find(object);
    assert(it == _objects.end());

    _objects.insert(object);
}

void Scavenger::unmark(const Object *object)
{
//    std::cout << "unmark: " << object->inspect() << std::endl;
    Objects::iterator it = _objects.find(object);
    assert(it != _objects.end());

    _objects.erase(it);
}
