// Exercising operators.

#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter a floating point value: ";
    double n;
    cin >> n;
    cout << "n == " << n << "\n"
         << "n+1 == " << n + 1 << "\n"
         << "3 times n == " << 3.0*n << "\n"
         << "2 times n == " << 2.0*n << "\n"
         << "n squared == " << n*n << "\n"
         << "half of n == " << n/2.0 << "\n"
         << "square root of n == " << sqrt(n) << "\n";
    return 0;
}