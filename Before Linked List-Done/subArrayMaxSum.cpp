////8.6
/////Brute force approach having time complexity O(n^3)
#include<iostream>
#include<climits>

using namespace std;

int main(){
    int i,j, k, n;
    cin>>n;
    int arr[n];
    for ( i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int maxSum=INT_MIN;
    for( i=0; i<n; i++){
        for( j=i; j<n; j++){
            int sum=0;
            for(k=i; k<=j; k++){
                sum+=arr[k];
            }
            maxSum=max(maxSum, sum);
        }
    }
    cout<<maxSum<<endl;
return 0;
}