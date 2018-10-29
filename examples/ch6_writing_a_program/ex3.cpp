// Implementation and use of a Token type for the calculator program.

#include "std_lib_facilities.h"

class Token {
public:
    char kind;
    double value;
    Token(char ch): kind(ch), value(0) { }
    Token(char ch, double val): kind(ch), value(val) { }
};

int main()
{
    Token t1 {'+'};
    // t1.kind = '+';

    Token t2 {'8', 3.14};
    // t2.kind = '8';
    // t2.value = 3.14;

    Token t3 = t2;

    vector<Token> tok;

    tok.push_back(Token {'8', 5.0});
    tok.push_back(Token {'*'});
    tok.push_back(Token {'8', 8.0});

    // Using multiplication.
    double d;
    for (int i = 0; i < tok.size(); ++i) {
        if (tok[i].kind == '*') {
            d = tok[i-1].value * tok[i+1].value;
        }
    }
    cout << d << "\n";

    return 0;
}