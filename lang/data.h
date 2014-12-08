#ifndef DATA_H
#define DATA_H

#include "garbage.h"
#include "error.h"

class Function;

// interface
class Data : virtual public Garbage
{
    struct TypeError : public Error
    {
        TypeError(const std::string &value, const std::string &name) :
            Error(std::string("Could not convert " + value + " to " + name)) {}
    };

protected:
    Data() = default;

public:
    virtual ~Data() {}

    std::string inspect() const override;

    virtual std::string value() const = 0;
    virtual bool getBoolean() const;
    virtual double getNumber() const;
};

#endif // DATA_H
