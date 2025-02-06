//
//
//TC: 

#include <bits/stdc++.h>
using namespace std;

int main() {
//     cout << "This is stored in the buffer and will be flushed later.";
//     cout << " This is also stored in the buffer.";
//     cout << " Now, let's flush the buffer explicitly!" << flush;
//     cout << endl; // This will also flush the buffer due to the newline character
//     return 0;



    // int lo = 1, hi = 1000000;
    // int ans = -1;
    // while(lo<=hi){
    //     int mid = (lo+hi)/2;
    //     cout << mid << endl;
    //     cout<<flush;
    //     string s;cin>>s;
    //     if(s == "<"){
    //         hi = mid - 1;
    //     }
    //     else{
    //         //>=
    //         ans = max(ans,mid);
    //         lo = mid + 1;
    //     }
    // }
    // cout<<"! "<<ans<<"\n";
    //23
    

    int lo = 1, hi = 1000000;
    int ans = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        cout << mid;
        string s;cin>>s;
        if(s == "<"){
            hi = mid - 1;
        }
        else{
            //>=
            ans = max(ans,mid);
            lo = mid + 1;
        }
    }
    cout<<"! "<<ans<<"\n";
    //23

}
// Interactive output
// 500000
// <
// 250000

// <
// 125000
// <
// 62500
// <
// 31250
// <
// 15625
// <
// 7812
// <
// 3906
// <
// 1953
// <
// 976
// <
// 488
// <
// 244
// <
// 122
// <
// 61
// <
// 30
// <
// 15
// >=
// 22
// >  
// 26
// <
// 24
// <
// 23