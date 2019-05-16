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

static inline unsigned indexOf(Symbol s) {
    unsigned index = static_cast<unsigned>(s);
    if (index < 9) return index;
    else return (index - 9);
}

static inline bool isTerminal(Symbol s) {
    return static_cast<unsigned>(s) >= 9;
}

struct Rule {
    Symbol lhs;
    std::vector<Symbol> rhs;
    bool isEmpty() const { return rhs.empty(); }
};

Rule none;
std::vector<std::vector<Rule>> ll1_table = {
    /* Parse */ { none, {Symbol::Parse, {Symbol::Stmt_list, }}, {Symbol::Parse, {Symbol::Stmt_list, }}, none, none, none, none, none, none, none, none, none, },
    /* Stmt_list */ { none, {Symbol::Stmt_list, {Symbol::stmt, }}, {Symbol::Stmt_list, {Symbol::stmt, }}, none, none, none, none, none, none, none, none, none, },
    /* stmt */ { none, {Symbol::stmt, {Symbol::Print, Symbol::Stmt_list_Prime, }}, {Symbol::stmt, {Symbol::Ident, Symbol::Stmt_list_Prime, }}, none, none, none, none, none, none, none, none, none, },
    /* Stmt_list_Prime */ { none, none, none, {Symbol::Stmt_list_Prime, {Symbol::Eol, Symbol::expr, Symbol::Stmt_list_Prime, }}, none, none, none, none, none, none, none, none, },
    /* expr */ { none, none, {Symbol::expr, {Symbol::Term, Symbol::expr_prime, }}, none, none, none, none, none, none, {Symbol::expr, {Symbol::Term, Symbol::expr_prime, }}, {Symbol::expr, {Symbol::Term, Symbol::expr_prime, }}, none, },
    /* Term */ { none, none, {Symbol::Term, {Symbol::Factor, Symbol::Term_prime, }}, none, none, none, none, none, none, {Symbol::Term, {Symbol::Factor, Symbol::Term_prime, }}, {Symbol::Term, {Symbol::Factor, Symbol::Term_prime, }}, none, },
    /* expr_prime */ { none, none, none, none, {Symbol::expr_prime, {Symbol::OpAssign, Symbol::Term, Symbol::expr_prime, }}, {Symbol::expr_prime, {Symbol::OpAdd, Symbol::Term, Symbol::expr_primedir, }}, none, none, none, none, none, none, },
    /* Factor */ { none, none, {Symbol::Factor, {Symbol::Ident, }}, none, none, none, none, none, none, {Symbol::Factor, {Symbol::Number, }}, {Symbol::Factor, {Symbol::OpenPar, Symbol::expr, Symbol::ClosePar, }}, none, },
    /* Term_prime */ { none, none, none, none, none, none, none, {Symbol::Term_prime, {Symbol::OpMul, Symbol::Factor, Symbol::Term_prim, }}, none, none, none, none, },
};
