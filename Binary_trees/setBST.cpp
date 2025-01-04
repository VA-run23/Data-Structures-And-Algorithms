////try these codes
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    set<int, greater<int>> setName;  

    s.insert(5);
    s.insert(2);
    s.insert(-8);
    s.insert(1);

    for (auto i : s) {
        cout << i << " ";
    }

    cout << "\nBy default set will be in ascending order\n";

    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\nThe reverse order is: ";

    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    cout << "The size of the set is: " << s.size() << "\n";
    cout << "Duplicates are not printed twice\n";

    set<int> s2;  
    s2.insert(1);
    s2.insert(3);
    s2.insert(5);
    
    
    cout << *s2.lower_bound(2) << "\n";
    cout << *s2.lower_bound(3) << "\n";
    cout << *s2.upper_bound(3) << "\n";
    cout << (s2.upper_bound(5) == s2.end()) << "\n";

  
    s.erase(3); 
    s.erase(s2.begin());
      for (auto i = s2.rbegin(); i != s2.rend(); ++i) {
        cout << *i << " ";
    }
    return 0;
}

// The expression (s2.upper_bound(5) == s2.end()) checks if there is no element in s2 that is greater than 5. If there is no such element, s2.upper_bound(5) will be equal to s2.end(), and the expression will evaluate to true (which is 1 when printed). Otherwise, it will evaluate to false (which is 0 when printed).
// So, the output will be:
// 1 if all elements in s2 are less than or equal to 5.
// 0 if there is at least one element in s2 that is greater than 5.