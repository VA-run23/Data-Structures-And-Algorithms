#include <bits/stdc++.h>
using namespace std;

#define vii vector<pii>
#define pii pair<int, int>
const int INF = 1e9;

// Global variables
int n, m;  // n: number of nodes, m: number of edges
const int N = 1e5 + 3;  // Defines max possible vertices for adjacency list
vii adjM[N];  // Adjacency list where each element is {neighbor, weight}
int cost = 0;  // Keeps track of total MST cost

// Vectors for MST construction
vector<int> dist(N, INF);  // Stores minimum known edge weight to each vertex
vector<int> parent(N, -1); // Stores the parent node from which each vertex was reached
vector<bool> vis(N, false); // Boolean vector to mark visited nodes

// Prim's Minimum Spanning Tree (MST) Algorithm
void primsMST(int source) {
    // Set to store {weight, vertex} pairs ensuring minimum weight edge is always processed first
    set<vector<int>> s; 
    
    dist[source] = 0;  // Distance of source from itself is zero
    s.insert({0, source});

    while (!s.empty()) {
        auto x = *(s.begin());  // Extract the smallest weight edge (first element)
        s.erase(x);  // Remove extracted element from set

        int u = x[1];  // Current node being processed
        int v = parent[x[1]];  // Parent node from which this node was reached
        int w = x[0];  // Weight of edge from parent to current node

        vis[u] = true;  // Mark node as visited
        cost += w;  // Accumulate total MST cost

        cout << "Edge Added: (" << v << " -> " << u << ") Cost: " << w << endl;

        // Traverse neighbors of current node (u)
        for (auto it : adjM[u]) { 
            int neighbor = it.first;  // Adjacent node
            int edgeWeight = it.second; // Edge weight between u and neighbor

            if (vis[neighbor]) 
                continue; // Skip already visited nodes

            if (dist[neighbor] > edgeWeight) { // If a smaller weight edge is found
                s.erase({dist[neighbor], neighbor});  // Remove old entry
                dist[neighbor] = edgeWeight;  // Update shortest known distance
                s.insert({dist[neighbor], neighbor});  // Insert updated distance
                parent[neighbor] = u;  // Set parent to track MST construction
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // u, v are vertices, w is edge weight

        // Since the graph is undirected, store edges in both directions
        adjM[u].push_back({v, w});
        adjM[v].push_back({u, w});
    }

    primsMST(0);
    cout << "Total MST Cost: " << cost << endl;

    return 0;
}