////Done

/*
Counting Sort Explanation:

1. Counting Occurrences: Count the frequency of each element in the input array.
2. Cumulative Frequency: Transform the count array into cumulative frequency to know how many elements are less than or equal to each value.
3. Placing Elements: Place each element from the input array into its correct position in the output array based on cumulative frequency.
4. Result: This ensures all elements are sorted correctly.
5. Advantages: Useful for stable sorting and handling duplicates efficiently.
*/
//The cumulative frequency helps in determining the position of the element in the sorted array
#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n){
    int k=arr[0];
    for(int i=0;i<n;i++){
        k=max(k, arr[i]);

    }
    int count[10]={0};//
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }
    for(int i=1; i<=k; i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0; i--){
        output[--count[arr[i]]]=arr[i];
    }
    for(int i=0; i<n; i++){
        arr[i]=output[i];
    }
}

int main(){
    int arr[]={1,3,2,3,4,1,6,4,3};
    countSort(arr, 9);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
//Hard coded input
int arr[]={1,3,2,3,4,1,6,4,3};


//Output:
/*
count = {0, 2, 3, 6, 8, 8, 9}; // storing the cumulative frequency

Traversing the input arr from right to left:
output = {_, _, _, _, _, 3, _, _, _} // since the count[3] = 6, placed 3 at index 5 in the output array
count = {0, 2, 3, 5, 8, 8, 9}
*/
