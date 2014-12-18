#include "micro_scheme.h"
#include "../lang/scavenger.h"
#include "../lang/global_context.h"

MicroScheme::MicroScheme(const std::string &str) : _str(str), _parser(_ss)
{
}

MicroScheme::~MicroScheme()
{
    Scavenger::destroy();
}

MicroScheme &MicroScheme::next(const std::string &str)
{
    crank();
    _str = str;
    return *this;
}

std::string MicroScheme::result()
{
    return crank()->value();
}

const Data *MicroScheme::crank()
{
    _ss << _str;
    return _parser.read()->invoke(GlobalContext::instance());
}
