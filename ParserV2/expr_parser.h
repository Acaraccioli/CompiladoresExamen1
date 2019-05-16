#ifndef _PARSER_H
#define _PARSER_H
#include <sstream>
#include <iostream>
#include "expr_lexer.h"

class Parser {
public:
  Parser(Lexer &lexer,std::ostringstream &out): lexer(lexer),out(out){}
  void parse();
  void Stmt_List();
  void  Stmt_list_Prime();
  void stmt();
  void expr();
  void expr_prime();
  void Term();
  void Term_prime();
  void Factor();

Symbol currToken;
int inicio;
   std::ostringstream &out;
   Lexer &lexer;
};

#endif
