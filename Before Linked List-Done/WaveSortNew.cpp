//Done
//TC : O(n)
//Output is in the form of cos wave. 
//High-low-high-low-.......

#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void waveSort(int arr[], int n){
    for(int i=1; i<n; i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr, i, i-1);
        }
        if(arr[i]>arr[i+1] && i<=n-2){//we can't get the element after n if i<= n-1
//i <= n-2: This ensures that i is not the last element or the second last element in the array. 
//This is because accessing arr[i+1] when i is the last element would result in an out-of-bounds error.
            swap(arr, i, i+1);
        }
    }
}

int main(){
    int arr[]={1,3,4,7,5,6,2};
    waveSort(arr, 7);
    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
////Output
//// 3 1 7 4 6 2 5 
//High-low-high-low-.......
// zero based index
// elements at odd index must be less than the value of the elements at even index