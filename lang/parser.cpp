#include "parser.h"
#include "utils.h"

Parser::Parser(std::istream &stream) : _stream(stream)
{
}

const Symbol *Parser::read()
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
    else if (bon(c))
    {
        _stream.putback(c);
        return readNumber();
    }
    else
    {
        _stream.putback(c);
        return readKeyword();
    }
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
            if (!word.empty())
            {
                throw SymbolError("Wrong using open braket as partition of ", word);
            }
        }
        else
        {
            word.push_back(c);
        }
    }

    if (word.empty())
    {
        throw SymbolError("Unexpected symbol instead keyword", c);
    }

    return new Keyword(word);
}

const Number *Parser::readNumber()
{
    char c;
    c = _stream.get();
    if (bon(c))
    {
        _stream.putback(c);
    }
    else
    {
        throw SymbolError("Expected number, but was readed", c);
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
    Arguments symbols;

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

        symbols.push_back(read());
    }

    if (symbols.empty())
    {
        throw ParseError("Invalid empty sequence");
    }

    return new Sequence(symbols);
}

bool Parser::bon(char c)
{
    if (std::isdigit(c))
    {
        return true;
    }
    else if (c == '-')
    {
        char n;
        n = _stream.get();
        _stream.putback(n);
        return std::isdigit(n);
    }
    else
    {
        return false;
    }
}

bool Parser::bos(char c) const
{
    return c == '(';
}

bool Parser::eos(char c) const
{
    return c == ')' || std::isspace(c);
}
