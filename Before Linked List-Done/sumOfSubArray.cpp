
//Done
//TC : O(n^2)
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int curr=0;

    for(int i=0; i<n;i++){
         curr=0;
        for(int j=i; j<n; j++){
        curr+=a[j];
        cout<<curr<<endl;
        }
    }
    return 0;
}
// //Input
// 5
// 1
// 2
// 3
// 4
// 5
////Output
// 1
// 3
// 6
// 10
// 15
// 2
// 5
// 9
// 14
// 3
// 7
// 12
// 4
// 9
// 5