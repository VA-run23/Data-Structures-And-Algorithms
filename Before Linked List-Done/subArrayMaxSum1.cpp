////8.6
/////my approach having errors,having time complexity O(n^2)

#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int curr=0;
    int maxSum=INT_MIN;

    for(int i=0; i<n;i++){
        curr=0;
        for(int j=i; j<n; j++){
            curr+=a[j];
            maxSum=max(curr, maxSum);

        }
    }
    cout<<maxSum<<endl;
    return 0;
}