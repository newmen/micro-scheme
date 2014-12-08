#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <sstream>

class Utils
{
public:
    template <class T>
    static std::string toString(const T &value);
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
