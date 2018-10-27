// First attempt at simple calculator program (updated, second iteration,
// has some mathematical implementation errors..on purpose).

#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter expression (we can handle +,-,*, and /): \n";
    cout << "Add an x to end expression (e.g. 1+2*3x): ";

    int lval = 0;
    int rval;

    cin >> lval;

    if (!cin){
        error("No first operand.");
    }

    for (char op; cin >> op;) {
        if (op != 'x') {
            cin >> rval;
        }
        if (!cin) {
            error("No second operand.");
        }

        switch(op) {
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '*':
                lval *= rval;
                break;
            case '/':
                lval /= rval;
            default:
                cout << "Result: " << lval << "\n";
                return 0;
        }
    }
    error("Bad expression:");
}