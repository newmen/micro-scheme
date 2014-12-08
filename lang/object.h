#ifndef OBJECT_H
#define OBJECT_H

#include <string>

// interface
class Object
{
protected:
    Object();

public:
    virtual ~Object();

    virtual std::string inspect() const;
};

#endif // OBJECT_H
