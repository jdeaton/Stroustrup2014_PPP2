/*
 * Simple calculator program.
 *
 * This program implements a basic expression calculator from Stroustrup
 * Programming: Principles and Practice, 2nd edition.
 *
 * Input from cin; output to cout;
 * The grammer for the input is:
 *   Calculation: Statement
 *                Print
 *                Quit
 *                Calculation Statement
 *   Statement: Expression
 *              Declaration
 *
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
 *   Declaration: "let" Name "=" Expression
 *
 *   Input comes from cin through the Token_stream called ts.
 */

#include "std_lib_facilities.h"

const char number = '8'; // floating-point literal token
const char quit = 'q';   // quit token
const char print = ';';  // print-to-screen token
const char name = 'a';   // variabl name token
const char let = 'L';    // declaration token
const string declkey = "let"; // declaration keyword
const string prompt = ">";    // prompt symbol used in console
const string result = "=";    // result symbol used in console


class Variable {
public:
    Variable(string var, double val): name(var), value(val) { }
    string name;
    double value;
};

vector<Variable> var_table;

double get_value(string s) {
// Return the value of the Variable named "s".
    for (const Variable& v : var_table) {
        if (v.name == s) {
            return v.value;
        }
    }
    error("get: Undefined variable.", s);
}

void set_value(string s, double d) {
// Set the Variable named "s" to value d.
    for (Variable& v : var_table) {
        if (v.name == s) {
            v.value = d;
            return;
        }
    }
    error("set: Undefined variable.", s);
}

bool is_declared(string var) {
// Check if variable is already in the var_table?
    for (const Variable& v : var_table) {
        if (v.name == var) {
            return true;
        }
    }
    return false;
}

double define_name(string var, double val) {
// Add (var,val) to var_table.
    if (is_declared(var)) {
        error(var, " declared twice.");
    }
    var_table.push_back(Variable(var, val));
    return val;
}

class Token {
public:
    char kind;
    double value;
    string name;
    explicit Token(char ch): kind(ch), value(0) { }
    Token(char ch, double val): kind(ch), value(val) { }
    Token(char ch, string n): kind(ch), name(n) { }
};

class Token_stream {
public:
    Token_stream();
    Token get();
    void putback(Token t);
    void ignore(char c); // ignore all characters until and including c
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
        case '=':
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
            if (isalpha(ch)) {
                string s;
                s += ch;

                while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) {
                    s += ch; // read variable names character at a time
                }

                cin.putback(ch);
                if (s == declkey) {
                    return Token {let};
                }
                return Token {name, s};
            }
            error("Bad token.");
    }
}

void Token_stream::ignore(char c) {
    // c represents the type of token we want to ignore until

    if (full && c == buffer.kind) { // first look in buffer
        full = false;
        return;
    }
    full = false; // clear out buffer
    char ch = 0;
    while (cin >> ch) { // search input stream for target character
        if (ch == c) {  // while ignoring all other characters
            return;
        }
    }
}

Token_stream ts;
double statement();
double expression();
double term();
double primary();
double declaration();

double statement() {
    Token t = ts.get();
    switch (t.kind) {
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

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

double declaration() {
// Assuming we have seen "let" in input.
// This function handles the case: name = expression.
// Declare a variable called "name" with the initial value "expression".
    Token t = ts.get();
    if (t.kind != name) {
        error("Name expected in the declaration.");
    }
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') {
        error("Missing = in declaration of ", var_name);
    }

    double d = expression();
    define_name(var_name, d);
    return d;
}

void clean_up_mess() {
    ts.ignore(print);
}

void calculate() {
    while (cin) {
        try {
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
            cout << result << statement() << '\n';
        }
        catch (exception& e) {
            cerr << e.what() << '\n';
            clean_up_mess();
        }
    }
}

int main()
{
    try {
        // Predefined named variables.
        define_name("pi", 3.1415926535);
        define_name("e", 2.7182818284);

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