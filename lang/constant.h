#ifndef CONSTANT_H
#define CONSTANT_H

#include "data.h"
#include "utils.h"

// abstract
template <typename T>
class Constant : public Data
{
protected:
    const T _value;

    Constant(const T &value) : _value(value) {}

public:
    std::string value() const override;
};

///////////////////////////////////////////////////////////////////////////////

template <typename T>
std::string Constant<T>::value() const
{
    return Utils::toString(_value);
}

#endif // CONSTANT_H
