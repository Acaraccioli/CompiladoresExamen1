#ifndef _PARSER_H
#define _PARSER_H

#include "expr_lexer.h"

class Parser {
public:
    Parser(Lexer& lexer): lexer(lexer) {}
    int parse();

private:
    Lexer& lexer;
};

#endif
