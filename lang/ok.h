#ifndef OK_H
#define OK_H

#include "data.h"

struct Ok : public Data
{
    Ok() = default;

    std::string value() const override;
    bool eql(const Data *) const override;
};

#endif // OK_H
