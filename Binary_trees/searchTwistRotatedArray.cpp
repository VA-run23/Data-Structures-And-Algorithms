//try this by comparing with first and last element after finding the pivot element
//
#include <bits/stdc++.h>
using namespace std;

int searchInRotatedArray(int arr[], int key , int left, int right){
    if(left > right){
        return -1;//how 
    }
    int mid = (left + right )/ 2;
    if(arr[mid] == key){
        return mid;
    }
    if(arr[left] <= arr[mid]){
        if(key  >= arr[left] && key <= arr[mid]){
            return searchInRotatedArray(arr, key , left, right);
        }
        return searchInRotatedArray(arr, key , mid+1, right);
    }
        if(key  >= arr[left] && key <= arr[right]){
            return searchInRotatedArray(arr, key , mid+1, right);
        }
        return searchInRotatedArray(arr, key , left, mid-1);
}

int main(){
    int arr[] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    int n=8, key = 8;
    int idx = searchInRotatedArray(arr, key , 0, n-1);
    if(idx == -1){
        cout<< "Key doesn't exist"<< endl;
    } else {
        cout<< "Key is present at idx: "<< endl;
    }
    return 0;
}