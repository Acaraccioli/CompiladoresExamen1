
#ifndef _EXPR_LEXER_H
#define _EXPR_LEXER_H

#include "lexer.h"
#include <iostream>
#include <string.h>
#include <sstream>

using std::string;
using std::cout;
using std::endl;

class ExprLexer {


    public:
     ExprLexer(std::istream &in) : in(in) {}
  


        const char* toString(Token tk);
        Token getNextToken();
        string getText() { return text; }
       
        std::istream& in;
       
        string text;
        char getNextChar() {
            char c = static_cast<char>(in.get());


            return c;
        }

        void ungetChar(char ch) {
            in.unget();
        }
        void reportError(char ch) {
            cout << "error at line " << endl;
        }



   
};
//fa2lexer --hdr lexer.h --src lexer.cpp ../fa/Start.jff

#endif