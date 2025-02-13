////done
////Namaste  
#include<iostream>
#include<string>
   
using namespace std;
   
int main(){
    // int n ;
    // cin>>n;
    // while(n>0){
    //     cout<<n<<endl;
    //     cin>>n;
    // }
    // return 0;
////////////Alternatively
    int n ;
    do{
        cin>>n;
        cout<<n<<endl;
    }while(n>0);
    return 0;
}
//this program  continuously read and print positive integers entered by the user. The loop terminates when the user enters a non-positive integer (0 or negative)