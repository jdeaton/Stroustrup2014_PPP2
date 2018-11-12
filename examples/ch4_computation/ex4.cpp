// while-loop and for-loop

#include "std_lib_facilities.h"

int main()
{
    // Calculate and print table of squares demonstrated with while-loop
    int i = 0;
    while (i < 100) {
        cout << i << "\t" << i*i << "\n";
        ++i;
    }

    // Calculate and print table of squares demonstrated with for-loop
    for (int i=0; i < 100; ++i) {
        cout << i << "\t" << i*i << "\n";
    }

    return 0;
}