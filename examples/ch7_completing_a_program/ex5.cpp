/*
 * Simple calculator program.
 *
 * This program implements a basic expression calculator from Stroustrup
 * Programming: Principles and Practice, 2nd edition.
 *
 * Input from cin; output to cout;
 * The grammer for the input is:
 *   Statement: Expression
 *              Print
 *              Quit
 *   Print: ;
 *   Quit: q
 *   Expression: Term
 *               Expression + Term
 *               Expression - Term
 *   Term: Primary
 *         Term * Primary
 *         Term / Primary
 *         Term % Primary
 *   Primary: Number
 *            ( Expression )
 *            - Primary
 *            + Primary
 *   Number: Floating-point literal
 *
 *   Input comes from cin through the Token_stream called ts.
 */

#include <cmath>
#include "std_lib_facilities.h"

const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = ">";
const string result = "=";

class Token {
public:
    char kind;
    double value;
    Token(char ch): kind(ch), value(0) { }
    Token(char ch, double val): kind(ch), value(val) { }
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

Token_stream::Token_stream():
        full(false), buffer(0)
{
}

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
        case print: // print, ';'
        case quit:  // quit, 'q'
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            return Token {ch}; // let characters represent themselves
        case '.':  // floating-point literal can start with a decimal
        case '0': case '1': case '2': case '3': case '4': // numeric literals
        case '5': case '6': case '7': case '8': case '9': // represent themselves
        {
            cin.putback(ch); // put digit back into input stream
            double val;
            cin >> val;
            return Token {number, val}; // '8' represents number
        }
        default:
            error("Bad token.");
    }
}

Token_stream ts;
double expression();
double term();
double primary();

double expression() {
    double left = term();
    Token t = ts.get();
    while(true) {
        switch (t.kind) {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

double term() {
    double left = primary();
    Token t = ts.get();
    while(true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/': {
                double d = primary();
                if(d == 0) {
                    error("Divide by zero.");
                }
                left /= d;
                t = ts.get();
                break;
            }
            case '%': {
                double d = primary();
                if (d == 0) {
                    error("Divide by zero.");
                }
                left = fmod(left, d);
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '(': {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') {
                error("') expected.");
            }
            return d;
        }
        case number:
            return t.value;
        case '-':
            return - primary();
        case '+':
            return primary();
        default:
            error("Primary expected.");
    }
}

void calculate() {
    while (cin) {
        cout << prompt;
        Token t = ts.get();

        while (t.kind == print) {
            t = ts.get();
        }

        if (t.kind == quit) {
            keep_window_open();
            return;
        }
        ts.putback(t);
        cout << result << expression() << '\n';
    }
}

int main()
{
    try {
        calculate();
        return 0;
    }
    catch (exception& e) {
        cerr << e.what() << "\n";
        keep_window_open("~~");
        return 1;
    }
    catch (...) {
        cerr << "Exception. \n";
        keep_window_open("~~");
        return 2;
    }
}