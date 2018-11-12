/* Ch 9. - Exercise 2
 *
 * Design and implement a Name_pairs class holding (name, age)
 * pairs where name is a string and age is a double. Represent
 * that as a vector<string> (called name) and a vector<double>
 * (called age) member. Provide an input operation read_names()
 * that prompts the user for an age for each name. Provide a
 * print() operation that prints out the (name[i],age[i]) pairs
 * (one per line) in the order determined by the name vector.
 * Provide a sort() operation that sorts the name vector in
 * alphabetical order and reorganizes the age vector to match.
 * Implement all "operations" as member functions. Test the
 * class.
*/
#include <iostream>
#include <vector>

using namespace std;

class Name_pairs {
public:
    void read_names();
    void read_ages();
    void sort();
private:
    vector<double> age;
    vector<string> name;
};

void Name_pairs::read_names() {
    cout << "Enter names ('*' to finish) \n";
    string nm;
    cin >> nm;
    while(nm != "*") {
        name.push_back(nm);
        cin >> nm;
    }
}

void Name_pairs::read_ages() {

}

void Name_pairs::sort() {

}


int main()
{
    Name_pairs people;
    people.read_names();
    return 0;
}

