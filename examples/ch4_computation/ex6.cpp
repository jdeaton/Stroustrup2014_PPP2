// function

#include "std_lib_facilities.h"

int main()
{
    // List initialization of a vector.
    vector<int> v = {5, 7, 9, 4, 6, 8};
    vector<string> philosophers = {"Kant", "Plato", "Hume", "Kierkegaard"};

    // Initialization without element values.
    vector<int> v1(6);
    vector<string> v2(4);

    // Traversing a vector.
    cout << "Traversing vector.\n";
    for (int i=0; i<v.size(); ++i)
        cout << v[i] << "\n";

    // Traversing a vector with range-based for-loop.
    cout << "Traversing vector w/ range-based for-loop.\n";
    for (int x : v)
        cout << x << "\n";

    // Growing a vector.
    cout << "Growing vector:\n";
    for (int x : v)
        cout << x << " ";
    cout << "\n";
    v.push_back(101);
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    // Numeric example, compute temperature statistics.
//    vector<double> temps;
//    for (double temp; cin >> temp; ) {
//        temps.push_back(temp);
//    }
//
//    double sum = 0;
//    for (double x : temps)
//        sum += x;
//    cout << "Average Temperature: " << sum/temps.size() << "\n";
//
//    sort(temps);
//    cout << "Median Temperature: " << temps[temps.size()/2] << "\n";

    // simple dictionary example of a vector.
    vector<string> words;
    for (string temp; cin >> temp; )
        words.push_back(temp);
    cout << "Number of words: " << words.size() << "\n";

    sort(words);

    for (int i=0; i<words.size(); ++i) {
        if (i==0 || words[i-1] != words[i])
            cout << words[i] << "\n";
    }


    return 0;
}
