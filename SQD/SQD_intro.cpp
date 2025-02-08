//Square Root Decomposition
//42.1 
// 

#include <bits/stdc++.h>
using namespace std;

//#define int long long
const int  N = 1e5+2, MOD = 1e9+7;


int main(){
     int n;cin>>n;
    vector<int> a(n);
    for(int i =0; i<n; i++){
        cin>>a[i];
    }
    int len = sqrt(n) +1;
    vector<int> b(len);
    for(int i  = 0; i<n; i++){
        b[i/len] += a[i];
    }
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        l--; r--;//to make it 0 based index from 1 based index
        int sum = 0;
        for(int i  = l ; i<= r;){
            if(i%len == 0 && i+len -1 <= r){
                sum += b[i/len];
                i+= len;
            }
            else{
                sum += a[i];
                i++;

            }
        }
        cout<<sum<<endl;

    }
    return 0;
}
// //Input
// 9
// 1 5 -2 6 8 -7 2 1 11
// 2
// 1 6
// 2 7
// //Output
// 11
// 12