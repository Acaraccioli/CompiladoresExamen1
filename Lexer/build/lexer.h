#ifndef __LEXER_H__
#define __LEXER_H__

enum class StateId {
    Start_q0,
    Start_q1,
    arith_q0,
    arith_q7,
    bcomment_q0,
    bcomment_q2,
    bcomment_q3,
    Lcomment_q0,
    Lcomment_q1,
    Number_q0,
    Number_q1,
    Number_q3,
    identifier_q0,
    identifier_q1,
};

enum class Token {
    ClosePar,
    Eof,
    Ident,
    Number,
    OpAdd,
    OpDiv,
    OpMul,
    OpSub,
    OpenPar,
};
#endif