#ifndef BOOLEAN_H
#define BOOLEAN_H

#include "constant.h"

class Boolean : public Constant<bool>
{
public:
    Boolean(bool value);

    std::string value() const override;
    bool getBoolean() const override;
};

#endif // BOOLEAN_H
