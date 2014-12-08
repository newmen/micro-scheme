#include "function.h"

std::string Function::inspect() const
{
    return std::string("Function") + Garbage::inspect();
}
