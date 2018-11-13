/*
 * Chapter 4. Drill.
 * Various computation/loop tasks (steps 1 to 5).
 */

#include "std_lib_facilities.h"

int main()
{
    double a {0.0};
    double b {0.0};
    double c {0.0};
    constexpr double tol = 1.0/100.0;
    while (cin >> a >> b)
    {
        c = a - b;
        if ((c > 0.0 && c < tol) || (c < 0.0 && c > -tol)) {
            cout << "the numbers are almost equal\n\n";
        }
        else if (a == b) {
            cout << "the numbers are equal\n\n";
        }
        else if (a < b) {
            cout << "the smaller value is: " << a << "\n";
            cout << "the larger value is: " << b << "\n\n";
        }
        else if (a > b) {
            cout << "the smaller value is: " << b << "\n";
            cout << "the larger value is: " << a << "\n\n";
        }
    }
    return 0;
}