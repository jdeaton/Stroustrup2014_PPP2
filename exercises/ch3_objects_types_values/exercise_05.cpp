/* Ch 3. - Exercise 5
 *
 * Modify the previous program to ask the user to enter floating-point values
 * and store them in double variables. Compare the outputs of the two programs
 * for some inputs of your choice. Are the results the same? Should they be?
 * What's the difference?
*/
#include "std_lib_facilities.h"

int main()
{
    cout << "Enter two doubles: ";
    int double1;
    int double2;
    cin >> double1 >> double2;
    
    if (double1 < double2) {
        cout << "Smaller: " << double1 << "\n";
        cout << "Larger:  " << double2 << "\n";
    }
    else if (double1 > double2) {
        cout << "Smaller: " << double2 << "\n";
        cout << "Larger:  " << double1 << "\n";
    }
    else { // Probably will never find equality in doubles
        cout << "Equal: " << double1 << " == " << double2 << "\n";
    }
        
    cout << "Sum: " << double1 + double2 << "\n";
    cout << "Difference: " << double1 - double2 << "\n";
    cout << "Product: " << double1 * double2 << "\n";
    cout << "Ratio: " << double1 / double2 << "\n";
    
    return 0;
}