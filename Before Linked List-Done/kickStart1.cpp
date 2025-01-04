//Done
//TC : O(n)
//longest subarray with same common difference
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans=2;//why initially answer is 2, 
    int pd=a[1]-a[0];
    int j=2;//counter variable (or loop variable) is initialised to 2(third element) as the difference between first two elements is already calculated (pd)
    int curr=2;//basically curr is the length of the sequence && as it requires two elements to get the difference , the minimum length of the sequence is 2
    
    while(j<n){//this loop runs for n-2 times , that is for all elements(after first two )
        if(pd==a[j]-a[j-1]){//this checks for streak of elements in the array
            curr++;
        }else{//if old streak of same difference is lost, a new streak with new difference is formed
            pd=a[j]-a[j-1];
            curr=2;
        }
        ans=max(ans, curr);
        j++;
    }
    cout<<ans;
    return 0;
}
////INput
//11 elements
// 22
// 33
// 44
// 44
// 55
// 44
// 33
// 22
// 11
// 0
// 1
////Output
// 6