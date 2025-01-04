//34.7
//DFS tree, Back Edge => cyclic
//Check as it is giving output of cycle is present even for acyclic

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

bool isCycle(int src, vector<vector< int>> &adj, vector<bool> &visited, int parent){
    visited[src] = true;
    for(auto i : adj[src]){
        if(i!= parent){
            if(visited[i]){
                return true;//if we pass through the previously visited node, the graph is cyclic
            }
            if(!visited[i] and isCycle(i, adj, visited, src)){
                return true;
            }
        }
    }
    return false;//if both condition fails the graph is not cyclic

}

int main(){
    int n , m; cin>>n>>m;
    vector<vector<int>> adj(n);
        int u, v;
    for(int i = 0; i< m; i++){
        cin>>u>>v;
        adj[u].push_back(v);//pushing values in adjacency matrix
        adj[v].push_back(u);
    }

    bool cycle = false;
    vector<bool> visited(n, false);//keeping track of visited nodes
    for(int i = 0; i< n; i++){
        if(!visited[i] and isCycle(i, adj, visited, -1)){//passing -1 as parent as index starts from 0
            cycle = true;//this line is impacting
        }
    }
    if(cycle) cout<<"Cycle is present."<<endl;
    else{
        cout<<"Cycle is not present"<<endl;
    } 
    return 0;
}
// //Input
// 4 4
// 0 1 
// 1 2
// 2 3
// 3 0

// //Output
// Cycle is present.


// Input
// 4 3
// 0 1 
// 1 2
// 2 3
// 3 0


// // //Output
// Cycle is not present
//THis is because even though the node connections are same, we are considering only 3 edges