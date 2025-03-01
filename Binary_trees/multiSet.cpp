//Done
//in multiset erase deletes all the duplicates also, so s.find() is used to delete a single value
#include <bits/stdc++.h>
using namespace std;

int main(){
    multiset<int> s;
    // set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    for(auto i : s)
        cout << i << " ";
        cout<<endl;
    s.erase(s.find(3));
    //The find function returns an iterator pointing to the element 3.
    //The erase function then takes this iterator and removes the element 3 from the container.
    ///THIS: is to perform single deletion instead of all occurances
    for(auto i : s)
        cout << i << " ";
        cout<<endl;
    s.erase(3);
    for(auto i : s)
        cout << i << " ";
        cout<<endl;
    return 0;
} 