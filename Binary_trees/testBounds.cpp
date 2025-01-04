#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 8, 3, 99, 5, 100};
    auto it = std::lower_bound(v.begin(), v.end(), 3);
    if (it != v.end()) {
        std::cout << "Lower bound of 3 is " << *it << "\n";
    } else {
        std::cout << "Element not found\n";
    }
    auto i = std::upper_bound(v.begin(), v.end(), 3);
    if (i != v.end()) {
        std::cout << "Upper bound of 3 is " << *i << "\n";
    } else {
        std::cout << "Element not found\n";
    }
    return 0;
}

////Output
// Lower bound of 3 is 3
// Upper bound of 3 is 4
// lower_bound: Finds the first element that is not less than the given value.
// upper_bound: Finds the first element that is greater than the given value.
/////Caution:: Always sort the values before using lower_bound and upper_bound functions to avoid unpredictable outpur
