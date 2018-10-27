// String operators.

#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter your first and last names: ";
    string first;
    string last;
    cin >> first >> last;
    string name = first + " " + last;
    cout << "Hello, " << name << "!\n";
    return 0;
}