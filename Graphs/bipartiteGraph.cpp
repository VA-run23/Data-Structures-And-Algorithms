//34.10

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

vvi adj;
vector<bool> vis;
vector<int> col;
bool bipart;

void color(int u, int curr){
    if(col[u] != -1 and col[u] != curr){
        bipart = false;
        return;
    }
    col[u] = curr;
    if(vis[u]){
        return;
    }
    vis[u] = true;
    for(auto i: adj[u]){
        color(i, curr ^ 1);
    }
}

int main(){
    int n, m; 
    bipart = true;
    cin >> n >> m;
    adj = vvi(n);
    vis = vector<bool>(n, false);
    col = vector<int>(n, -1);
    
    for(int i = 0; i < m; i++){
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }  

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            color(i, 0);
        }
    }
    
    if(bipart){
        cout << "Graph is bipartite" << endl;
    } else {
        cout << "Graph is not bipartite" << endl;
    }
    
    return 0;
}


// //Input
// 3 3
// 0 1 1 2
// 2 0

// //Output
// Graph is not bipartite
