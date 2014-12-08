#include "parser.h"
#include "arguments.h"
#include "utils.h"

Parser::Parser(std::istream &stream) : _stream(stream)
{
}

const Statement *Parser::read()
{
    skipSpaces();

    char c;
    c = _stream.get();
    if (!_stream)
    {
        return nullptr;
    }
    else if (c == '(')
    {
        return readSequence();
    }
    else if (std::isdigit(c))
    {
        _stream.putback(c);
        return readNumber();
    }
    else if (std::isalpha(c))
    {
        _stream.putback(c);
        return readKeyword();
    }
    else
    {
        throw SymbolError("Unexpected symbol", c);
    }

    return nullptr; // for except compilation warning
}

void Parser::skipSpaces()
{
    char c;
    while (true)
    {
        c = _stream.get();
        if (!std::isspace(c))
        {
            _stream.putback(c);
            break;
        }
    }
}

const Keyword *Parser::readKeyword()
{
    std::string word;
    char c;
    while (true)
    {
        c = _stream.get();
        if (eos(c))
        {
            _stream.putback(c);
            break;
        }
        else if (bos(c))
        {
            if (word.empty())
            {
                throw ParseError("Expected word, but sequence begin was readed");
            }
            else
            {
                throw SymbolError("Wrong using open braket as partition of ", word);
            }
        }
        else
        {
            word.push_back(c);
        }
    }

    return new Keyword(word);
}

const Number *Parser::readNumber()
{
    char c;
    c = _stream.get();
    if (!std::isdigit(c))
    {
        throw SymbolError("Expected number, but was readed", c);
    }
    else
    {
        _stream.putback(c);
    }

    double number;
    _stream >> number;
    c = _stream.get();
    if (eos(c))
    {
        _stream.putback(c);
    }
    else
    {
        throw SymbolError("Unexpected symbol after number", c);
    }

    return new Number(number);
}

const Sequence *Parser::readSequence()
{
    const Keyword *name = nullptr;
    Statements statements;

    char c;
    while (true)
    {
        skipSpaces();
        c = _stream.get();
        if (eos(c))
        {
            break;
        }
        else
        {
            _stream.putback(c);
        }

        if (!name)
        {
            name = readKeyword();
        }

        statements.push_back(read());
    }

    if (!name)
    {
        throw ParseError("Invalid empty sequence");
    }

    return new Sequence(name, statements);
}

bool Parser::bos(char c) const
{
    return c == '(';
}

bool Parser::eos(char c) const
{
    return c == ')' || std::isspace(c);
}
