//34.8 
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

// Function to check if there is a cycle in the graph using DFS
bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &stack){
    stack[src] = true; // Mark the current node in the recursion stack
    if(!visited[src]){
        visited[src] = true; // Mark the current node as visited
        for(auto i : adj[src]){
            if(!visited[i] && isCycle(i, adj , visited, stack)){
                return true; // If an adjacent node is not visited and there is a cycle, return true
            }
            if(stack[i]){
                return true; // If an adjacent node is in the recursion stack, return true (cycle detected)
            }
        }
    }
    stack[src] = false; // Remove the current node from the recursion stack
    return false; // No cycle detected
}
int main(){
    int n , m ; 
    cin>>n>>m;
    vector<vector<int> > adj(n);
    int u, v;
    for(int i  = 0 ; i < m; i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool cycle = false;

    vector<int> stack(n, 0);
    vector<bool> visited(n, 0);


    for(int i=0; i<n; i++){
        if(!visited[i] and isCycle(i, adj, visited, stack)){
            cycle = true;
        }
    }
    if(cycle){
        cout<<"Cycle is present";
    }else{
        cout<<"Cycle is not present";
    }

    return 0;
}


// //Input
// 4 3 
// 0 1
// 1 2
// 2 1

// //Output
// Cycle is present


// //INput
// 4 3 
// 0 1
// 1 2
// 2 3
// //Output
// Cycle is not present