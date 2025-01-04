//Done
//The time complexity of your merge sort implementation is O(n log n). 
//This is because merge sort divides the array into two halves, recursively sorts each half, and then merges the sorted halves.
// The division step takes O(log n) time, and the merging step takes O(n) time, resulting in an overall time complexity of O(n log n) for all cases (best, average, and worst)
#include <bits/stdc++.h>
using namespace std;

long long merge(int arr[], int l, int mid, int r){//assuming that both half of the array are already sorted
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];//a and b are temp arrays
    int b[n2];
    for(int i=0; i<n1; i++){
        a[i]=arr[l+i];
    }
    for(int i=0; i<n1; i++){
        a[i]=arr[l+i];
    }
    for(int i=0; i<n2; i++){
        b[i]=arr[mid+1+i];
    }
    int i=0, j=0, k=l;
    // i is the index for a[].
    // j is the index for b[].
    // k is the index for arr[]
    long long inv = 0;
    while(i<n1 and j<n2){
        if(a[i]<=b[j]){
            arr[k]=a[i];
            k++;i++;
        }else{ // a[i]>b[j]
            arr[k]=b[j];
            inv+=n1-i;//important part of the program
            k++; j++;
        }
    }while(i<n1){//transferring remaining elements of a[i] 
        arr[k]=a[i];
        k++; i++;
    }while(j<n2){//transferring remaining elements of b[j] 
        arr[k]=b[j];
        k++; j++;
    }
    return inv;
}

long long mergeSort(int arr[], int l, int r){
    long long inv=0;
    if(l<r){//this itself forms the base case
        int mid=(l+r)/2;
        inv += mergeSort(arr, l , mid);//just dividing array into two halves
        inv += mergeSort(arr, mid+1, r);
        inv += merge(arr, l , mid, r);
    }
    return inv;
 }

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<mergeSort(arr, 0, n-1);//(array, left_boundary, right_boundary)
    return 0;
}