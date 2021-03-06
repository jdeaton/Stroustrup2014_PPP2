// Implementating a Token_stream into the calculator program.

#include "std_lib_facilities.h"

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
        case '8':
            return t.value;
        case '-':
            return - primary();
        case '+':
            return primary();
        default:
            error("Primary expected.");
    }
}

int main()
{
    try {
        while (cin) {
            cout << ">";
            Token t = ts.get();

            while (t.kind == ';') {
                t = ts.get();
            }

            if (t.kind == 'q') {
                keep_window_open();
                break;
            }
            ts.putback(t);
            cout << "=" << expression() << '\n';
        }
        keep_window_open();
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