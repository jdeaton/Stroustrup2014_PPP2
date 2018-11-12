// Demonstrates constexpr, const, and type conversion.

#include "std_lib_facilities.h"

int main()
{
    // Constant expression value must be initialized at compile time
    // and does not change.
    constexpr double pi = 3.14159;
    double r = 1.0;
    double c = 2*pi*r;

    // const value not known at compile time, but does not change
    // once it is initialized.
    int a = 1;
    const int b = 2*a;

    // Implicit type conversion on assignment.
    double d = a/2; // not conversion occurs after integer division!
    cout << d << "\n";
    d = double(a)/2;
    cout << d << "\n"; //

    // Explicit type conversions.
    d = double(6);
    d = double{8};
}