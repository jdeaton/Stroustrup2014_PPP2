// Implementation and use of a Token type for the calculator program.

#include "std_lib_facilities.h"

class Token {
public:
    char kind;
    double value;
};

Token get_token();
double expression();
double term();
double primary();

Token get_token() {
}

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
    try {
        while(cin) {
            cout << expression() << "\n";
        }
    }
    catch(exception& e) {
        cerr << e.what() << "\n";
        return 1;
    }
    catch(...) {
        cerr << "Exception. \n";
        return 2;
    }

    return 0;
}