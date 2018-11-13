/*
 * Chapter 4. Drill.
 * Various computation/loop tasks (steps 5 to 11).
 */

#include "std_lib_facilities.h"

bool valid_unit(const string& unit);
double convert_to_meters(double x, const string& unit);

int main()
{
    vector<double> all_values;
    double val {0.0};
    string unit;
    cout << "Enter value w/ unit: ";
    cin >> val >> unit;
    if (!valid_unit(unit)) {
        return 1;
    }
    val = convert_to_meters(val, unit);
    unit = "m";
    cout << "Value: " << val << " " << unit << "\n";
    all_values.push_back(val);

    double smallest {val};
    double largest {val};
    double sum {val};

    while ((cin >> val >> unit) && valid_unit(unit))
    {
        val = convert_to_meters(val, unit);
        unit = "m";
        cout << "Value: " << val << " " << unit << " ";
        sum += val;
        all_values.push_back(val);

        if (val < smallest) {
            smallest = val;
            cout << "(smallest so far) ";
        }
        if (val > largest) {
            largest = val;
            cout << "(largest so far) ";
        }
        cout << "\nEnter value w/ unit: ";
    }

    cout << "SMALLEST: " << smallest << " m\n";
    cout << "LARGEST: " << largest << " m\n";
    cout << "SUM: " << sum << " m\n";

    cout << "ALL VALUES (SORTED): \n";
    sort(all_values);
    for (double val : all_values) {
        cout << val << " meters \n";
    }

    return 0;
}

bool valid_unit(const string& unit) {
    if (unit == "cm" ||
        unit == "m" ||
        unit == "in" ||
        unit == "ft") {
        return true;
    }
    else {
        cout << "\n INVALID UNIT: " << unit;
        return false;
    }
}

double convert_to_meters(double x, const string& unit) {
    constexpr double cm_to_m = 100.0;
    constexpr double in_to_cm = 2.54;
    constexpr double ft_to_in = 12;

    if (unit == "m") return x;
    else if (unit == "cm") return x/cm_to_m;
    else if (unit == "in") return x*in_to_cm/cm_to_m;
    else if (unit == "ft") return x*ft_to_in*in_to_cm/cm_to_m;
}