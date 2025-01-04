
//Done
using namespace std;
//use vector header files
#include <bits/stdc++.h>
int main(){
////Vectors are dynamic arrays that can grow and shrink in size, making them very versatile for various applications.
//declaring vector
vector<int> a; // Declares a vector of integers
vector<int> b(10); // Declares a vector of integers with 10 elements, all initialized to 0
vector<int> c(10, 5); // Declares a vector of integers with 10 elements, all initialized to 5

////accessing
a[0] = 1; // Sets the first element to 1
int x = a[0]; // Gets the first element


////adding and removing 
a.push_back(2); // Adds 2 to the end of the vector
a.pop_back(); // Removes the last element


////Iterating Over a Vector
for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " "; // Access elements using the index
}

for (auto& i : a) {//The syntax for (auto& i : a) means “for each element i in the container a”.
//auto& i
// auto: This keyword tells the compiler to automatically deduce the type of i based on the type of elements in the container a. For example, if a is a vector of integers (vector<int>), i will be deduced as an int.
// &: The ampersand (&) means that i is a reference to the elements in a. This means i directly refers to the elements in a rather than creating a copy of each element.
    cout << i << " "; // Range-based for loop
}

// Common Functions
// Size: a.size() returns the number of elements in the vector.
// Empty: a.empty() returns true if the vector is empty.
// Clear: a.clear() removes all elements from the vector.
// Resize: a.resize(new_size) changes the size of the vector.

    return 0;
}


////Key Differences
// Syntax:
    // Array: int arr[n];
    // Vector: std::vector<int> vec(n);
// Size:
    // Array: Fixed size, determined at compile time.
    // Vector: Dynamic size, can be changed at runtime.
// Memory Management:
    // Array: Managed by the compiler, usually on the stack.
    // Vector: Managed by the std::vector class, usually on the heap.
// Flexibility:
    // Array: Less flexible, fixed size.
    // Vector: More flexible, can grow or shrink as needed.

// Example Comparison
// // Array declaration
// int arr[5]; // Fixed size array of 5 integers

// // Vector declaration
// std::vector<int> vec(5); // Vector initialized with 5 integers and can be altered