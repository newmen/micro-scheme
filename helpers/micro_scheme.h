#ifndef MICRO_SCHEME_H
#define MICRO_SCHEME_H

#include <string>

class MicroScheme
{
    const std::string _str;

public:
    MicroScheme(const std::string &str);
    ~MicroScheme();

    std::string result() const;
};

#endif // MICRO_SCHEME_H
