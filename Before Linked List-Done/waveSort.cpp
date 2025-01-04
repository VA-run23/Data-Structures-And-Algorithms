//self code
//better luck next time
#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void waveSort(int arr[],int  n){
int i=0;
    for(int i=0;i<=n-2; i+=2){
        if(arr[i]<=arr[i+2] && arr[i+2]>=arr[i+3]){
            continue;
        }
        swap(arr, i, i+1);
    }
}

int main(){
    int arr[]={1,5,0,3,7,9,4,8,3};//9 elem
    waveSort(arr, 9);
      for(int i=0; i<9; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}