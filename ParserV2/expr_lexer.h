#ifndef _LEXER_H
#define _LEXER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
enum class Symbol: unsigned {
    Parse = 0,
    Stmt_list = 1,
    stmt = 2,
    Stmt_list_Prime = 3,
    expr = 4,
    Term = 5,
    expr_prime = 6,
    Factor = 7,
    Term_prime = 8,
    Eof = 9,
    Print = 10,
    Ident = 11,
    Eol = 12,
    OpAssign = 13,
    OpAdd = 14,
    expr_primedir = 15,
    OpMul = 16,
    Term_prim = 17,
    Number = 18,
    OpenPar = 19,
    ClosePar = 20,
    Epsilon = 21
};

using SymbolInfo = std::pair<Symbol, std::string>;

class Lexer {
public:
    Lexer(const std::vector<SymbolInfo>& tklst): tklist(tklst) {
        it = tklist.begin();
    }

    Symbol getNextToken() {
        if (it == tklist.end()) {
            return Symbol::Eof;
        }
        Symbol tk = it->first;
        text = it->second;
        it++;
        
        return tk;
    }
    
    bool hasTokens() { return it != tklist.end(); }
    std::string getText() { return text; }

private:
    std::string text;
    std::vector<SymbolInfo> tklist;
    std::vector<SymbolInfo>::iterator it;
};
#endif
