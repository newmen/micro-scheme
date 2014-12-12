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
    bool eql(const Data *other) const override;
};

///////////////////////////////////////////////////////////////////////////////

template <typename T>
std::string Constant<T>::value() const
{
    return Utils::toString(_value);
}

template <typename T>
bool Constant<T>::eql(const Data *other) const
{
    const Constant<T> *con = dynamic_cast<const Constant<T> *>(other);
    return con && _value == con->_value;
}

#endif // CONSTANT_H
