//Done
//TC : O(nlogn) for average case,
//TC : O(n^2), for worst case

//We are placing pivot to its correct position
#include <bits/stdc++.h>
using namespace std;


void swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[], int l, int r){
    int pivot=arr[r];
    int i=l-1;//initially i has the value of index behind the starting point of the array
    for(int j=l; j<r; j++){//r is n-1, and we are looping till r-1, as pivot element is at index r
        if(arr[j]<pivot){
            i++;//now arr[i] denotes least number less than pivot
            swap(arr, i,j);
        }
    }
    //By the end of this loop all the element till i are less than pivot and all the element after i are greater than pivot, so swap arr[i+1] with pivot
    swap(arr, i+1, r);//since i will be pointing the number less than pivot, but all the numbers after index i are greater than pivot 
    return i+1;//so the new pivot element's inces is i+1 which is returned back to quicksort
}

void quickSort(int arr[], int l, int r){
    if(l<r){
        int pi=partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);

    }
}

int main(){
    int arr[5]={5,4,3,2,1};
    quickSort(arr, 0,4);//passing the value of r as n-1, or r is the last index
    cout<<arr<<endl;//this prints the address of the array
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}