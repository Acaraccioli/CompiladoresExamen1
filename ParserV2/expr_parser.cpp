#include "expr_parser.h"
 void Parser::parse()
 {
     
    currToken=lexer.getNextToken();
    Stmt_List();
 }

   void Parser::stmt(){
       if(currToken==Symbol::Print)
       Stmt_list_Prime();
       else if(currToken==Symbol::Ident)
       Stmt_list_Prime();
      
   }
  void Parser::Stmt_List()
  {
      stmt();
  }
  void  Parser::Stmt_list_Prime()
  {
      if(currToken==Symbol::Eol)
      {
                    currToken=lexer.getNextToken();

          expr();
          Stmt_list_Prime();
      }

  }

  void Parser::expr()
  {
      Term();
      expr_prime();


  }
  void Parser::expr_prime()
  {
      if(currToken==Symbol::OpAdd || currToken==Symbol::OpAssign)
      {
                    currToken=lexer.getNextToken();

          Term();
          expr_prime();
      }

  }
  void Parser::Term()
  {
      Factor();
      Term_prime();

  }
  void Parser::Term_prime()
  {
       if(currToken==Symbol::OpMul )
      {
          currToken=lexer.getNextToken();
          Factor();
            Term_prime();      
}

  }
  void Parser::Factor()
  {
      if(currToken==Symbol::Number )
      {
          currToken=lexer.getNextToken();
      }
      if(currToken==Symbol::Ident )
      {
          currToken=lexer.getNextToken();
      }
      if(currToken==Symbol::OpenPar )
      {
          currToken=lexer.getNextToken();
          expr();
          if(currToken==Symbol::ClosePar )
        {
          currToken=lexer.getNextToken();
         }
      }


  }
