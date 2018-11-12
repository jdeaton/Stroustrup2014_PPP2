/*
 * Simple program to detect repeated words with counter to demonstrate composite
 * assignment operators.
 *
 * Test with: The cat cat jumped
 *            She she laughed He He He because what he did did not look very very good good
*/

#include "std_lib_facilities.h"

int main()
{
    int number_of_words = 0;
    string previous = " ";
    string current;
    while (cin >> current) {
        ++number_of_words;
        if (previous == current)
            cout << "Word number: " << number_of_words
                 << " Repeated word: " << current << "\n";
        previous = current;
    }
    return 0;
}