#ifndef NUMBER_H
#define NUMBER_H

#include "constant.h"
#include "statement.h"
#include "context.h"

class Number : public Constant<double>, public Statement
{
public:
    Number(double value);

    const Data *call(const Context *) const override;

    double getNumber() const override;
};

#endif // NUMBER_H
