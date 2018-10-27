// Read/write first and last name.

#include "std_lib_facilities.h"

int main()
{
    std::cout << "Please enter your first and last name:\n";
    string first_name;
    string last_name;
    std::cin >> first_name >> last_name;
    std::cout << "Hello, " << first_name << " " << last_name << "!\n";
    return 0;
}