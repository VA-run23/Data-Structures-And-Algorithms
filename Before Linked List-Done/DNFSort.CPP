//Done
//DNF=Dutch National Flag sort
//0,1,2 sort
//TC : O(n)

#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void dnfSort(int arr[], int n){
    int low=0; int mid=0; int high =n-1;//these are just indexes
    while(mid<=high){//// Iterate until mid index is less than or equal to high index
        if(arr[mid]==0){
            swap(arr, low, mid);
            low++, mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr, mid, high);
            high--;
        }
    }
}
int main(){
    int arr[]={1,0,2,1,0,1,2,1,2};
    dnfSort(arr, 9);
    for(int i=0; i<9; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// The Dutch National Flag sort (DNF sort) effectively sorts the array by placing all 0s to the left and all 2s to the right. 
// The 1s automatically fall into place in the middle as the 0s and 2s are swapped.

//Even if 0 is swapped from last to the mid index, we are swapping from mid index only , so it will sort the array 