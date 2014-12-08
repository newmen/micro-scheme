#ifndef NAMED_H
#define NAMED_H

#include <string>

// interface
class Named
{
protected:
    Named() = default;
public:
    virtual ~Named() {}

    virtual std::string name() const = 0;
};

#endif // NAMED_H
