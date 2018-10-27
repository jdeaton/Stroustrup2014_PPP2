// Read and write a first name and age.

#include "std_lib_facilities.h"

int main()
{
    std::cout << "Please enter your first name and age:\n";
    string first_name;
    int age;
    std::cin >> first_name;
    std::cin >> age;
    std::cout << "Hello, " << first_name << " (age " << age << ")!\n";
    return 0;
}