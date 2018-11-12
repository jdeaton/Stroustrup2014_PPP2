/*
 * Chapter 3. Drill.
 * Letter writing program with user input.
 */

#include "std_lib_facilities.h"

int main()
{
    std::cout << "Enter the name of the person you want to write to: \n";
    string first_name;
    std::cin >> first_name;

    std::cout << "Enter the recipient age: \n";
    int age;
    std::cin >> age;
    if (age < 0 || age > 110) simple_error("You're kidding!");

    std::cout << "Enter the name of another friend to ask about: \n";
    string friend_name;
    std::cin >> friend_name;

    std::cout << "Enter friend gender (m=male, f=female): \n";
    char friend_gender;
    std::cin >> friend_gender;

    std::cout << "Enter sender name: \n";
    string sender_name;
    std::cin >> sender_name;

    std::cout << "Hello, " << first_name << "!\n\n";

    std::cout << "\tHow are you? I am fine. This is some dummy text for a stupid letter. ";
    std::cout << "Have you seen " << friend_name << " lately? ";
    std::cout << "If you see " << friend_name << " please ask ";
    if (friend_gender == 'm') std::cout << "him ";
    if (friend_gender == 'f') std::cout << "her ";
    std::cout << "to call me. ";

    std::cout << "I hear you just had a birthday and you are " << age << " years old. ";
    if (age < 12)
        std::cout << "Next year you will be " << age+1 << ". ";
    else if (age == 17)
        std::cout << "Next year you will be able to vote. ";
    else if (age > 70)
        std::cout << "I hope you are enjoying retirement. ";

    std::cout << "Sincerely, " << sender_name;

    return 0;
}