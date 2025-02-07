//40.1
//

#include <bits/stdc++.h>
using namespace std;

const int  N = 1e5+2, MOD = 1e9+7;

int a[N], tree[4*N];

void build(int node, int st, int en){
    if(st == en){
        tree[node] = a[st];
        return ;
    }
    int mid = (st+en)/2;
    build(2*node, st, mid);//left child
    build(2*node+1, mid+1, en);

    tree[node] = tree[2*node]+ tree[2*node+1];//we change this as per our need 
}

int main(){
    int n; cin>>n;
    for(int i = 0; i<n ; i++){
        cin>>a[i];

    }
    build(1, 0, n-1);
    for(int i  =1; i<15; i++){
         cout<<tree[i] <<endl;
    }
    return 0;
}



// //Input
// 8
//  5 3 2 4 1 8 6 10

// //Output
// 39
// 14
// 25
// 8
// 6
// 9
// 16
// 5
// 3
// 2
// 4
// 1
// 8
// 6


    //             5 3 2 4 1 8 6 10
    //          /                      \
    //       5 3 2 4                1 8 6 10
    //     /     \                 /          \
    //   5 3     2 4           1 8          6 10
    //  /  \     /  \          /   \        /   \
    // 5    3   2    4       1     8      6     10



    //             39
    //          /      \
    //       14         25
    //      / \        /   \
    //     8   6      9     16
    //    / \ / \    / \   /  \
    //   5  3 2  4  1   8 6   10
