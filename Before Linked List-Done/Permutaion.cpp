    //distinct elements
    #include <bits/stdc++.h>
    using namespace std;

    vector<vector<int>> ans; // ans is a global vector to store all permutations.
    // Declares a vector of vectors to store permutations

    void permute(vector<int>& a, int idx) {//initially idx is having the value 0
        if (idx == a.size()) {
            ans.push_back(a); // Base Case: If idx equals the size of the vector a, the current permutation is added to ans.
            return;
        }//push_back() plays a key role
        for (int i = idx; i < a.size(); i++) {
            swap(a[i], a[idx]);//swap is inbuilt function in vector
            permute(a, idx + 1);
            swap(a[i], a[idx]);//backtrack
            //backtracking because we are calling function with counter variable
        }
        return;
    }

    int main() {
        int n; 
        cin >> n;
        vector<int> a(n);
        for (auto& i : a) { // Using '&' with 'auto' to reference elements of vector 'a' directly, avoiding copies
            cin >> i;
        }
        
        permute(a, 0); // Call the permute function to generate permutations.
        for (auto v : ans) {
            for (auto i : v)
                cout << i << " ";
            cout << endl;
        }

        return 0;
    }
