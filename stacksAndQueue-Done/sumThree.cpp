//Done
//TC: O(n^2)

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int target; cin>>target;
    vector<int> a(n);
    for(auto &i: a){
        cin>>i;
    }
    bool found =false;
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        int lo=i+1, hi=n-1;
        while(lo<hi){
            int current=a[i]+a[lo]+a[hi];// Calculating the sum of elements a[i], a[lo], and a[hi] which change dynamically during each iteration
            if(current == target){
                found = true;
                break;
            }if (current<target){
                lo++;
            } else{
                hi--;
            }
        }
    }
    if(found){
        cout<<"True";
    }else{
        cout<<"False";
    }
    return 0;
}

////input
//6 24
//12 3 6 8 34 25
////output
//False

// //INput 
// 6 24
// 12 3 6 6 34 25

// //Output
// True