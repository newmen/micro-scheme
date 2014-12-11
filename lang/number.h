#ifndef NUMBER_H
#define NUMBER_H

#include "constant.h"
#include "context.h"

class Number : public Constant<double>
{
public:
    Number(double value);

    double getNumber() const override;
};

#endif // NUMBER_H
