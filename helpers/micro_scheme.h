#ifndef MICRO_SCHEME_H
#define MICRO_SCHEME_H

#include <string>
#include <sstream>
#include "../lang/parser.h"

class MicroScheme
{
    std::string _str;
    std::stringstream _ss;

    Parser _parser;

public:
    MicroScheme(const std::string &str);
    ~MicroScheme();

    MicroScheme &next(const std::string &str);
    std::string result();

private:
    const Data *crank();
};

#endif // MICRO_SCHEME_H
