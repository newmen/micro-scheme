#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <sstream>
#include "object.h"
#include "data.h"

class Context;

class Utils
{
public:
    template <class T>
    static std::string toString(const T &value);

    static const Data *getData(const Context *context, const Object *object);
};

///////////////////////////////////////////////////////////////////////////////

template <class T>
std::string Utils::toString(const T &value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

#endif // UTILS_H
