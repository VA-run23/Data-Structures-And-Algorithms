//done
//This program sorts the characters in the given string in descending order and then prints the sorted string
//TC : (O(n logn))
#include<algorithm>//TO USE sort function
#include<iostream>

using namespace std;

// int main() {//this just gives the greatest character in the string
//     string s = "3214135150984547098";
//     char greater = '0'; // Initialize to the smallest possible digit character

//     // Loop through each character in the string
//     for (int i = 0; i < s.length(); i++) {
//         // Update greater if the current character is larger
//         if (s[i] > greater)
//             greater = s[i];
//     }

//     // Output the greatest character found
//     cout << "Greatest character: " << greater << endl;
//     return 0;
// }


int main(){
    string s="2342452345264767";
    sort(s.begin(), s.end(), greater<int>());
    //// the sort function in C++ sorts the same string in place. This means that the original string is modified and sorted directly, rather than creating a new sorted string
    cout<<s<<endl;
    return 0;
}
// // output
// 7766554444332222