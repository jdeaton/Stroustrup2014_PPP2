/* Ch 3. - Exercise 7
 *
 * Redo the previous exercise, but using string values instead of strings.
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
    cout << "Enter three words: ";
    vector<string> strings(3);
    cin >> strings[0] >> strings[1] >> strings[2];

    sort(strings.begin(), strings.end());

    for (int i = 0; i < strings.size(); ++i) {
        cout << strings[i] << ", ";
    }

    return 0;
}