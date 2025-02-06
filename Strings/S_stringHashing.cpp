//39.1.1
//

#include <bits/stdc++.h>
using namespace std;

const int  N = 1e5+2, MOD = 1e9+7;


int main(){
    vector<string> strings = {"aa", "ab", "aa", "b", "cc", "b"};
    sort(strings.begin(), strings.end());
    // Time complexity: O(nmlog(n))
    int distinct = 0;
    for (int i = 0; i < strings.size(); i++) {
        if (i == 0 || strings[i] != strings[i-1]) {
            distinct++;
        }
    }
    cout << distinct << "\n";

    return 0;
}