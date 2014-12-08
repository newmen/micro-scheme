#include "object.h"
#include <sstream>
#include "scavenger.h"

Object::Object()
{
    // There is direct pointer to Garbage
    Scavenger::instance()->mark(this);
}

Object::~Object()
{
    Scavenger::instance()->unmark(this);
}

std::string Object::inspect() const
{
    std::stringstream ss;
    ss << "<" << this << ">";
    return ss.str();
}
