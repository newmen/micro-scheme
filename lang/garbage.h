#ifndef GARBAGE_H
#define GARBAGE_H

#include <string>

// interface
class Garbage
{
protected:
    Garbage();

public:
    virtual ~Garbage();

    virtual std::string inspect() const;
};

#endif // GARBAGE_H
