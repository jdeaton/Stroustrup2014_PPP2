// Read and write a first name and age (2nd version), with default
// age value.

#include "std_lib_facilities.h"

int main()
{
    std::cout << "Please enter your first name and age:\n";
    string first_name;
    int age = -1;
    std::cin >> first_name >> age;
    std::cout << "Hello, " << first_name << " (age " << age << ")!\n";
    return 0;
}