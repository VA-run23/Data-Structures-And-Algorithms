//DONE
//TC: O(1), Since there are no loops or recursive calls that depend on the size of the input, the overall time complexity remains constant, i.e.,
#include <iostream>
#include <algorithm> // For std::max
using namespace std;

bool check(int x, int y, int z) {
    int a = max(x, max(y, z));
    int b, c;
    if (a == x) {//code to get max of three in variable 'a'
        b = y;
        c = z;
    } else if (a == y) {
        b = x;
        c = z;
    } else {
        b = z;
        c = y;
    }
    // Now the maximum of the three values is in a
    if (a * a == b * b + c * c) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    if (check(x, y, z)) {
        cout << "Pythagorean triplet";
    } else {
        cout << "Not a Pythagorean triplet";
    }
    return 0;
}

// //Output
// 5 4 3
// Pythagorean triplet