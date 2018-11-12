// function

#include "std_lib_facilities.h"

// Square function declaration.
int square(int x);

int main()
{
    // Calculate and print table of squares demonstrated with for-loop & function.
    for (int i=0; i < 100; ++i) {
        cout << i << "\t" << square(i) << "\n";
    }

    return 0;
}

// Square function definition.
int square(int x) {
    return x*x;
}