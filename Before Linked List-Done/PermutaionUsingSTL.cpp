//distinct elements
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
// void permute(vector<int>& a, int idx) {
//     if (idx == a.size()) {
//         ans.push_back(a); // Base Case: If idx equals the size of the vector a, the current permutation is added to ans.
//         return;
//     }
//     for (int i = idx; i < a.size(); i++) {
//         swap(a[i], a[idx]);
//         permute(a, idx + 1);
//         swap(a[i], a[idx]);
//     }
//     return;
// }

int main() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    do{
        ans.push_back(a);
    }while(next_permutation(a.begin(), a.end()));//next_permutation() is an inbuilt function in C++ from the <algorithm> library    
    for (auto v : ans) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
