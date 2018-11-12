// if-statements.

#include "std_lib_facilities.h"

int main()
{

    // if-statement example 1.
    int a = 0;
    int b = 0;
    cout << "Please enter two integers:\n";
    cin >> a >> b;

    if (a < b)
        cout << "max(" << a << "," << b << ") is " << b << "\n";
    else if (b < a)
        cout << "max(" << a << "," << b << ") is " << a << "\n";
    else
        cout << a << " == " << b << "\n";

    // if-statement example 2.
    constexpr double cm_per_inch = 2.54;
    double length = 1.0;
    char unit;
    cout << "Enter a length followed by a unit (c or i): \n";
    cin >> length >> unit;

    if (unit == 'i')
        cout << length << "in == " << cm_per_inch*length << "cm \n";
    else if (unit == 'c')
        cout << length << "cm == " << length/cm_per_inch << "in \n";
    else
        cout << "Sorry, I don't understand a unit called '" << unit << "'\n";
}