/////A array which stores the address of elements of other arrays  
//TC: ( O(n) + O(n) + O(n) = O(n) )
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n], *ads[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=0; i<n; i++){
        ads[i]=&arr[i];
    }
    for (int i = 0; i < n; i++) {
        cout << ads[i] << " "; // Print the addresses
    }
    cout << endl;
return 0;
}