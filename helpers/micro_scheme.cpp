#include "micro_scheme.h"
#include <sstream>
#include "../lang/scavenger.h"
#include "../lang/global_context.h"
#include "../lang/parser.h"

MicroScheme::MicroScheme(const std::string &str) : _str(str)
{
}

MicroScheme::~MicroScheme()
{
    Scavenger::destroy();
}

std::string MicroScheme::result() const
{
    std::stringstream ss;
    ss << _str;

    Parser parser(ss);
    const Symbol *symbol = parser.read();
    const Data *data = symbol->invoke(GlobalContext::instance());

    return data->value();
}
