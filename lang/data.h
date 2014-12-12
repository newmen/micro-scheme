#ifndef DATA_H
#define DATA_H

#include "symbol.h"
#include "error.h"

// interface
class Data : public Symbol
{
    struct TypeError : public Error
    {
        TypeError(const std::string &value, const std::string &name) :
            Error(std::string("Could not convert " + value + " to " + name)) {}
    };

protected:
    Data() = default;

public:
    std::string inspect() const override;
    const Data *invoke(const Context *) const override;

    virtual std::string value() const = 0;
    virtual bool eql(const Data *other) const = 0;

    virtual bool getBoolean() const;
    virtual double getNumber() const;
};

#endif // DATA_H
