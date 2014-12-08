#ifndef ERROR_H
#define ERROR_H

#include <string>

class Error
{
    std::string _msg;

public:
    Error(const std::string &message) : _msg(message) {}

    const std::string &message() const { return _msg; }
};

#endif // ERROR_H
