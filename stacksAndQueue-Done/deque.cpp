//Done
#include<deque>
#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    dq.push_back(3);
    dq.push_front(4);
    for(auto v: dq){
        cout<<v<<" ";
    }
    cout<<endl;
    dq.pop_back();
    dq.pop_front();
     for(auto v: dq){
        cout<<v<<" ";
    }
    cout<<endl;
    cout<<dq.size();
    return 0;
}

//Output
// 4 2 1 3 
// 2 1 
// 2