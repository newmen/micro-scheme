#ifndef OK_H
#define OK_H

#include "data.h"

class Ok : public Data
{
    static Ok *__instance;

    Ok() = default;

public:
    static Ok *instance();

    std::string value() const override;
    bool eql(const Data *) const override;
};

#endif // OK_H
