/* Ch 3. - Exercise 4
 *
 * Write a program that prompts the user to enter two integer
 * values. Store these values in int variables named val1 and
 * val2. Write your program to determine the smaller, larger,
 * sum, difference, product, and ratio of these values and
 * report them to the user.
*/
#include "std_lib_facilities.h"

int main()
{
    cout << "Enter two integers: ";
    int int1;
    int int2;
    cin >> int1 >> int2;
    
    if (int1 < int2) {
        cout << "Smaller: " << int1 << "\n";
        cout << "Larger:  " << int2 << "\n";
    }
    else if (int1 > int2) {
        cout << "Smaller: " << int2 << "\n";
        cout << "Larger:  " << int1 << "\n";
    }
    else {
        cout << "Equal: " << int1 << " == " << int2 << "\n";
    }
        
    cout << "Sum: " << int1 + int2 << "\n";
    cout << "Difference: " << int1 - int2 << "\n";
    cout << "Product: " << int1 * int2 << "\n";
    cout << "Ratio: " << int1 / int2 << "\n";
    
    return 0;
}