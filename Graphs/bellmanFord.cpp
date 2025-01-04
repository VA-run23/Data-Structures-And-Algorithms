#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) __builtin_popcount(x) // counts the number of set bits (1s) in the binary representation of x

// Main function
int main(){

    int n, m;
    cin >> n >> m; // Read number of vertices (n) and edges (m)
    vvi edges; // Vector to store edges
    rep(i, 0, m){
        int u, v, w;
        cin >> u >> v >> w; // Read each edge (u, v) with weight (w)
        edges.push_back({u, v, w}); // Add edge to the list
    }
    int src; 
    cin >> src; // Read the source vertex

    vi dist(n, INT_MAX); // Initialize distances with infinity
    dist[src] = 0; // Distance to the source is 0
    for(int i = 1; i <= n-1; i++){
        bool change = false; // Flag to check if any distance was updated
        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            // Relax the edge if a shorter path is found
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                change = true; // Mark that a change was made
            }
        }
        if(!change) break; // If no change was made, exit early
    }
    
    // Print the shortest distances from the source to all vertices
    for(auto i : dist){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

// //Input
// 6 7
// 3 2 6
// 5 3 1
// 0 1 5
// 1 5 -3
// 1 2 -2
// 3 4 -2
// 2 4 3
// 0
// //Output
// 0 5 3 3 1 2