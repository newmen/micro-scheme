#ifndef PARSER_H
#define PARSER_H

#include <istream>
#include "error.h"
#include "number.h"
#include "keyword.h"
#include "statement.h"

class Parser
{
    std::istream &_stream;

    struct ParseError : public Error
    {
        ParseError(const std::string &message) :
            Error(message + ", when parsing") {}
    };

    struct SymbolError : public ParseError
    {
        SymbolError(const std::string &message, char symbol) :
            SymbolError(message, std::string(&symbol, 1)) {}

        SymbolError(const std::string &message, const std::string &symbol) :
            ParseError(message + ": \"" + symbol + "\"") {}
    };

public:
    Parser(std::istream &stream);

    const Symbol *read();

private:
    void skipSpaces();

    const Keyword *readKeyword();
    const Number *readNumber();
    const Statement *readStatement();

    bool bon(char c);
    bool bos(char c) const;
    bool eos(char c) const;
};

#endif // PARSER_H
