//Done
//TC : O(n)
#include <bits/stdc++.h>
using namespace std;

void dec(int n){
    if(n==1){
        cout<<"1"<<endl;
        return;
    }
    cout<<n<<endl;
    dec(n-1);
}

void inc(int n){
     if(n==1){
        cout<<"1"<<endl;
        return;
    }
    inc(n-1);
    cout<<n<<endl;
}
int main(){
    int n;
    cin>>n;
    dec(n);
    cout<<"Change of order"<<endl;
    inc(n);
return 0;
}

// ////Input
// 7
// ////output
// 7
// 6
// 5
// 4
// 3
// 2
// 1
// Change of order
// 1
// 2
// 3
// 4
// 5
// 6
// 7