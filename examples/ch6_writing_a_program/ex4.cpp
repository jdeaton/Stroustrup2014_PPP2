// Implementation and use of a Token type for the calculator program.

#include "std_lib_facilities.h"

class Token {
public:
    char kind;
    double value;
};

class Token_stream {
public:
    Token_stream();
    Token get();
    void putback(Token t);
private:
    bool full {false};
    Token buffer;
};

void Token_stream::putback(Token t) {
    if (full) { error("Cannot putback() into a full buffer."); }
    buffer = t;
    full = true;
}

Token Token_stream::get() {
    if (full) { // return token in buffer if present
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;

    switch (ch) {
        case ';': // print
        case 'q': // quit
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token {ch};
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch); // put digit back into input stream
            double val;
            cin >> val;
            return Token {'8', val}; // '8' represents number
        }
        default:
            error("Bad token.");
    }
}


Token get_token() {
    return Token();
}
double expression();
double term();
double primary();

double expression() {
    double left = term();
    Token t = get_token();
    while(true) {
        switch(t.kind) {
            case '+':
                left += term();
                t = get_token();
                break;
            case '-':
                left -= term();
                t = get_token();
                break;
            default:
                return left;
        }
    }
}

double term() {
    double left = primary();
    Token t = get_token();
    while(true) {
        switch(t.kind) {
            case '*':
                left *= primary();
                t = get_token();
                break;
            case '/': {
                double d = primary();
                if(d == 0) {
                    error("Divide by zero.");
                }
                left /= d;
                t = get_token();
                break;
            }
            default:
                return left;
        }
    }
}

double primary() {

}

int main()
{
    return 0;
}