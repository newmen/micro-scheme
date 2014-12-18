#ifndef OK_H
#define OK_H

#include "tools/singleton.h"
#include "data.h"

class Ok : public Singleton<Ok, Data>
{
    friend class Singleton;
    Ok() = default;

public:
    std::string value() const override;
    bool eql(const Data *) const override;
};

#endif // OK_H
