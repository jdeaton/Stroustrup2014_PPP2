/*
 * Simple program to detect repeated words.
 *
 * Test with: The cat cat jumped
 *            She she laughed He He He because what he did did not look very very good good
*/

#include "std_lib_facilities.h"

int main()
{
    string previous = " ";
    string current;
    while (cin >> current) {
        if (previous == current)
            cout << "Repeated word: " << current << "\n";
        previous = current;
    }
    return 0;
}