/* Ch 3. - Exercise 6
 *
 * Write a program that prompts the user to enter three integer values, and
 * then outputs the values in numerical sequence separated by commas.
 *
 * Probably not supposed to know about vectors and sort function at this point
 * in the textbook, but I am going to use them for simplicity.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cout << "Enter three integers: ";
    vector<int> integers(3);
    cin >> integers[0] >> integers[1] >> integers[2];

    sort(integers.begin(), integers.end());

    for (int i = 0; i < integers.size(); ++i) {
        cout << integers[i] << ", ";
    }

    return 0;
}