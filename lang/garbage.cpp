#include "garbage.h"
#include <sstream>
#include "scavenger.h"

Garbage::Garbage()
{
    Scavenger::instance()->mark(this);
}

Garbage::~Garbage()
{
    Scavenger::instance()->unmark(this);
}

std::string Garbage::inspect() const
{
    std::stringstream ss;
    ss << "<" << this << ">";
    return ss.str();
}
