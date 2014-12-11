#ifndef OK_H
#define OK_H

#include "data.h"

class Ok : public Data
{
public:
    Ok() = default;

    std::string value() const override;
};

#endif // OK_H
