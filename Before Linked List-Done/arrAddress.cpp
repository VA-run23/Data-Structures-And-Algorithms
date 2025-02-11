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
        ads[i]=&arr[i];//Store the address of a[i] in ads[i]
    }
    for (int i = 0; i < n; i++) {
        cout << ads[i] << " "; // Print the addresses
    }
    cout << endl;
return 0;
}
// //Input
// 5
// 1 2 3 4 5 
// //Output
// 0x61fec8 0x61fecc 0x61fed0 0x61fed4 0x61fed8 
