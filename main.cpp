#include <iostream>
#include "lang/scavenger.h"
#include "lang/global_context.h"
#include "lang/symbol.h"
#include "lang/parser.h"
#include "lang/error.h"

int main()
{
    std::istream &input = std::cin;
    Parser parser(input);

    // REPL
    while (true)
    {
        const Symbol *symbol = nullptr;
        std::cout << ">> ";

        try
        {
            symbol = parser.read();
            if (symbol)
            {
                const Data *data = symbol->invoke(GlobalContext::instance());
                std::cout << data->value() << std::endl;
            }
            else
            {
                std::cout << std::endl;
                break;
            }
        }
        catch (Error e)
        {
            std::cerr << e.message() << std::endl;
            input.ignore();
        }
    }

    Scavenger::destroy();
    return 0;
}

