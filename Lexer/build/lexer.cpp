Token ExprLexer::getNextToken() {
    StateId state = StateId::Start_q0;
    int ch = getNextChar();

    while (true) {
        switch (state) {
            // Start
            case StateId::Start_q0:
                state = StateId::Start_q1;
                text="";
                break;
            case StateId::Start_q1:
                if ((ch == '\n') || (ch == ' ') || (ch == '\t')) {
                    state = StateId::Start_q1;
                    ch = getNextChar();
                } else if (ch == EOF) {
                    return Token::Eof;
                } else {
                    // Trying next automaton 'arith'
                    state = StateId::arith_q0;
                }
                break;
            // arith
            case StateId::arith_q0:
                if (ch == '+') {
                    text += ch;
                    return Token::OpAdd;
                } else if (ch == '/') {
                    text += ch;
                    return Token::OpDiv;
                } else if (ch == '*') {
                    text += ch;
                    return Token::OpMul;
                } else if (ch == '(') {
                    text += ch;
                    state = StateId::arith_q7;
                    ch = getNextChar();
                } else if (ch == ')') {
                    text += ch;
                    return Token::ClosePar;
                } else if (ch == '-') {
                    text += ch;
                    return Token::OpSub;
                } else {
                    // Trying next automaton 'Lcomment'
                    state = StateId::Lcomment_q0;
                }
                break;
            case StateId::arith_q7:
                if (ch == '*') {
                    state = StateId::bcomment_q0;
                    ch = getNextChar();
                } else {
                    ungetChar(ch);
                    return Token::OpenPar;
                }
                break;
            // bcomment
            case StateId::bcomment_q0:
                state = StateId::bcomment_q2;
                break;
            case StateId::bcomment_q2:
                if (ch == '*') {
                    state = StateId::bcomment_q3;
                    ch = getNextChar();
                } else {
                    state = StateId::bcomment_q2;
                    ch = getNextChar();
                }
                break;
            case StateId::bcomment_q3:
                if (ch == ')') {
                    state = StateId::Start_q0;
                    ch = getNextChar();
                } else {
                    state = StateId::bcomment_q2;
                }
                break;
            // Lcomment
            case StateId::Lcomment_q0:
                if (ch == '#') {
                    state = StateId::Lcomment_q1;
                    ch = getNextChar();
                } else {
                    // Trying next automaton 'Number'
                    state = StateId::Number_q0;
                }
                break;
            case StateId::Lcomment_q1:
                if (ch == '\n') {
                    state = StateId::Start_q0;
                    ch = getNextChar();
                } else if (ch == EOF) {
                    return Token::Eof;
                } else {
                    state = StateId::Lcomment_q1;
                    ch = getNextChar();
                }
                break;
            // Number
            case StateId::Number_q0:
                if (isdigit(ch)) {
                    text += ch;
                    state = StateId::Number_q1;
                    ch = getNextChar();
                } else {
                    // Trying next automaton 'identifier'
                    state = StateId::identifier_q0;
                }
                break;
            case StateId::Number_q1:
                if (ch == '.') {
                    text += ch;
                    state = StateId::Number_q3;
                    ch = getNextChar();
                } else if (isdigit(ch)) {
                    text += ch;
                    state = StateId::Number_q1;
                    ch = getNextChar();
                } else {
                    ungetChar(ch);
                    return Token::Number;
                }
                break;
            case StateId::Number_q3:
                if (isdigit(ch)) {
                    text += ch;
                    state = StateId::Number_q3;
                    ch = getNextChar();
                } else {
                    ungetChar(ch);
                    return Token::Number;
                }
                break;
            // identifier
            case StateId::identifier_q0:
                if (ch == '_') {
                    text += ch;
                    state = StateId::identifier_q1;
                    ch = getNextChar();
                } else {
                    reportError(ch);
                    ch = getNextChar();
                    state = StateId::Start_q0;
                }
                break;
            case StateId::identifier_q1:
                if ((isdigit(ch)) || (isalpha(ch)) || (ch == '_')) {
                    text += ch;
                    state = StateId::identifier_q1;
                    ch = getNextChar();
                } else {
                    ungetChar(ch);
                    return Token::Ident;
                }
                break;
        }
    }
}
const char* ExprLexer::toString(Token tk) {
    switch (tk) {
        case Token::ClosePar: return "ClosePar";
        case Token::Eof: return "Eof";
        case Token::Ident: return "Ident";
        case Token::Number: return "Number";
        case Token::OpAdd: return "OpAdd";
        case Token::OpDiv: return "OpDiv";
        case Token::OpMul: return "OpMul";
        case Token::OpSub: return "OpSub";
        case Token::OpenPar: return "OpenPar";
        default: return "Unknown";
    }
}