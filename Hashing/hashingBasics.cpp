//
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
//ff: Shorthand for accessing the first element of a pair.
//ss: Shorthand for accessing the second element of a pair.
#define setBits(x) __builtin_popcount(x)
// The __builtin_popcount(x) function is a built-in function provided by GCC (GNU Compiler Collection).
//  It counts the number of set bits (1s) in the binary representation of an integer x. This is also known as the “population count” or “Hamming weight” of the number.


int main() {
    vi numbers = {3, 5, 7, 9};
    rep(i, 0, numbers.size()) {
        cout << "Number of set bits in " << numbers[i] << " is " << setBits(numbers[i]) << endl;
    }

    
    map<int, vector<int>> m;
    //map<int, vi> m;////You can define it like this also
    map<int, vi> :: iterator it;//it is the iterator variable
    // An iterator is an object that allows you to traverse the elements of a container (like a map) without exposing the underlying structure.
    ////Conclusion: map<int, vi>::iterator it; declares an iterator named it for a map where the keys are integers and the values are vectors of integers.
    return 0;
}
////Difference between pair and maps
// Purpose:
//     pair: Used to store two related values.
//     map: Used to store key-value pairs with unique keys.
// Structure:
//     pair: Simple container with two elements.
//     map: Associative container with key-value pairs, sorted by keys.
// Access:
//     pair: Access elements using first and second.
//     map: Access elements using keys.
// Ordering:
//     pair: No inherent ordering.
//     map: Elements are ordered by keys.
// Complexity:
//     pair: Constant time access to elements.
//     map: Logarithmic time complexity for insertion, deletion, and access due to underlying balanced tree structure1.


//// Key Difference
//     pair: Holds two values together as a single unit.
//     map: Associates each key with a single value, but you can think of it as a collection of pair objects where each key-value pair is unique.

// If you need to associate a key with multiple values, you might use a map where the value is a container (like a vector or set):
//     std::map<int, std::vector<std::string>> m;
//     m[1] = {"one", "uno", "eins"};
// Here, the key 1 is associated with a vector of strings.


////Difference between map and unordered_map
// The main difference between `map<int, int>` and `unordered_map<int, int>` in C++ lies in their underlying data structures and the order of elements:

// 1. **Data Structure**:
//    - **`map<int, int>`**: This is implemented as a self-balancing binary search tree (usually a Red-Black Tree). This ensures that the elements are stored in a sorted order based on the keys.
//    - **`unordered_map<int, int>`**: This is implemented as a hash table. The elements are not stored in any particular order.

// 2. **Order of Elements**:
//    - **`map<int, int>`**: The elements are stored in ascending order of their keys. This means that when you iterate over the map, you will get the elements in sorted order.
//    - **`unordered_map<int, int>`**: The elements are stored in an arbitrary order. The order depends on the hash function and the current state of the hash table, so it can appear random.

// 3. **Performance**:
//    - **`map<int, int>`**: Operations like insertion, deletion, and lookup take O(log n) time due to the tree structure.
//    - **`unordered_map<int, int>`**: Operations like insertion, deletion, and lookup take average O(1) time due to the hash table structure. However, in the worst case (e.g., many hash collisions), these operations can degrade to O(n) time.

// 4. **Memory Usage**:
//    - **`map<int, int>`**: Generally uses more memory due to the tree structure which requires pointers for parent, left, and right children.
//    - **`unordered_map<int, int>`**: Uses memory for the hash table and the elements, but typically less overhead compared to the tree structure.

// Here's a quick comparison in code:

// ```cpp
// #include <iostream>
// #include <map>
// #include <unordered_map>

// int main() {
//     std::map<int, int> ordered_map;
//     std::unordered_map<int, int> unordered_map;

//     // Example data
//     int a[] = {5, 3, 8, 6, 2, 7, 4, 1};
//     int n = sizeof(a) / sizeof(a[0]);

//     // Filling the ordered map
//     for (int i = 0; i < n; ++i) {
//         ordered_map[a[i]]++;
//     }

//     // Filling the unordered map
//     for (int i = 0; i < n; ++i) {
//         unordered_map[a[i]]++;
//     }

//     // Printing the ordered map
//     std::cout << "Ordered map:" << std::endl;
//     for (auto it = ordered_map.begin(); it != ordered_map.end(); ++it) {
//         std::cout << it->first << " " << it->second << std::endl;
//     }

//     // Printing the unordered map
//     std::cout << "Unordered map:" << std::endl;
//     for (auto it = unordered_map.begin(); it != unordered_map.end(); ++it) {
//         std::cout << it->first << " " << it->second << std::endl;
//     }

//     return 0;
// }
// ```

// In this example, the `ordered_map` will print elements in sorted order, while the `unordered_map` will print elements in an arbitrary order. This demonstrates the key differences in how these containers manage and access their elements.
