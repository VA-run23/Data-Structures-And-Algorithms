//34.5
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) __builtin_popcount(x)

const int N = 1e5+2;
bool vis[N];
vi adj[N];//array of vectors


void dfs(int node){

    //preorder
    vis[node] = 1;
    // cout<<node<<" "<<endl;

    //INorder
    // cout<<"In-order"<<endl;

    for(auto  i: adj[node]){
        if(vis[i]); 
        else{
            dfs(i);
        }
    }

    //Post order
    // cout<<"Post order"<<endl;
    cout<<node<<" "<<endl;


}

int main(){
    int n, m;
    cin>> n >> m;

    for(int i=0; i< n; i++){//i<=n??
    vis[i] = false;
    }
    int x, y;
    for(int i = 0; i< m ; i++){
        cin>>x>> y;
        adj[x].push_back(y);
        adj[y].push_back(x);


    }
    dfs(1);//considering 1 as root node

    return 0;
}
// //Input
// 7  7
// 1 2 
// 1 3 
// 2 4 
// 2 5
// 2 6
//  2 7
//  3 7

//  //output////Pre-order
// 1 
// 2 
// 4 
// 5 
// 6 
// 7 
// 3

// ////Post order
// 4 
// 5 
// 6 
// 3 
// 7 
// 2 
// 1 






