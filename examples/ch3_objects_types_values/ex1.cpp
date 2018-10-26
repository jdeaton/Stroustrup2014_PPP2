// Read and write a first name.

#include "std_lib_facilities.h"

int main()
{
    std::cout << "Please enter your first name (followed by 'enter'):\n";
    string first_name;
    std::cin >> first_name;
    std::cout << "Hello, " << first_name << "!\n";
    return 0;
}