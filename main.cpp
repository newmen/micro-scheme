#include <iostream>
#include "error.h"
#include "lang/scavenger.h"
#include "lang/global_context.h"
#include "lang/statement.h"
#include "lang/parser.h"

int main()
{
    Parser parser(std::cin);

    try
    {
        // REPL
        while (true)
        {
            const Statement *statement = nullptr;
            std::cout << ">> ";

            statement = parser.read();
            if (statement)
            {
                const Data *data = statement->call(GlobalContext::instance());
                std::cout << data->value() << std::endl;
            }
            else
            {
                std::cout << std::endl;
                break;
            }
        }
    }
    catch (Error e)
    {
        std::cerr << e.message() << std::endl;
        Scavenger::destroy();
        return 1;
    }

    Scavenger::destroy();
    return 0;
}

