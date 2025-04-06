//34.14

#include <bits/stdc++.h>
using namespace std;

#define vii vector<pii>
#define pii pair<int, int>
const int INF = 1e9;
// Global variables
int n, m;
const int N = 1e5 + 3;
vii adjM[N];
int cost = 0;

vector<int> dist(N), parent(N);//parent vector is to store the node value whose nearest neighbour is to be found
vector<bool> vis(N);

void primsMST(int source) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    set<vector<int>> s;//stores the vector, {weight, vertex}
    ///NOTE: weight is used as the first element vector<pair> as it is sorted in ascending order by default.
    ///So, the first element of the vector will be the minimum weight edge.
    dist[source] = 0;
    s.insert({0, source});//insert the distance of the source node from itself as 0

    while (!s.empty()) {
        auto x = *(s.begin());//extracting the top element. As begin() points to the first element of the set, it will be the minimum weight edge.
        //thus x is a vector of size 2, where x[0] is the weight and x[1] is the vertex
        s.erase(x);//since we are processing this node, it is removed from the set
        vis[x[1]] = true; //marking it as visited so that it won't be processed again
        int u = x[1];//current vertex/node
        int v = parent[x[1]];//previous node(from which we reached this node)
        int w = x[0];// edge weight between these two nodes
        ///NOTE: since we are using set, it ensures that the minimum weight edge is always at the top of the set.
        cout << u << " " << v << " " << w << endl;
        cost += w;

/// NOTE: adjM[x[1]] represents the list of neighboring nodes and edge weights for the current node.
/// Each entry in adjM[x[1]] is a pair {neighbor, weight}, where:
/// - it.first refers to the neighboring node.
/// - it.second represents the weight of the edge connecting the current node (u) to it.first.

        for (auto it : adjM[x[1]]) {//this loops over the neighbors of x[1], which is u
            if (vis[it.first])
                continue;//skip the visited nodes
            if (dist[it.first] > it.second) {//if the weight of the edge to a node from the current node is less than the previous weight of that node
                s.erase({dist[it.first], it.first}); // Remove the old entry from the set
                dist[it.first] = it.second; // Update shortest distance to adjM[neighboradjM[
                s.insert({dist[it.first], it.first}); // Insert updated distance into set
                parent[it.first] = x[1]; // Set the parent of the neighboring node (it.first) to the current node (x[1]), 
                                        // indicating the node from which it was reached in the MST.
                //As the algorithm progresses, parent[v] holds the vertex that connects v to the MST via the shortest edge found.
            }
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

// Global Variables
/*
    n -> int: Stores the number of nodes (vertices) in the graph.
    m -> int: Stores the number of edges in the graph.
    INF -> const int: Represents a very large number (used as an upper bound for distances).
    N -> const int: Defines the maximum possible number of vertices (1e5 + 3).
    adjM -> vector<pii> adjM[N]: Stores adjacency lists for each vertex, where each pair <int, int>
            contains a neighboring vertex and edge weight.
    cost -> int: Keeps track of the total cost of the Minimum Spanning Tree (MST).


 Vectors
    dist -> vector<int>: Stores the shortest known distance from the MST to each vertex.
                      Initially set to INF.
    parent -> vector<int>: Tracks the parent node from which each vertex was reached in the MST.
    vis -> vector<bool>: Boolean vector that marks visited nodes during MST construction.

Inside primsMST() Function
    s -> set<vector<int>>: A set that stores {weight, vertex} pairs and helps efficiently pick the minimum weight edge.
    x -> vector<int>: Extracted from s, contains {weight, vertex} of the minimum edge.
    u -> int: Stores the current vertex being processed.
    v -> int: Holds the parent of u, i.e., the node from which u was reached.
    w -> int: Stores the edge weight of u.
    it.first -> int: Represents a neighboring node (adjacent to x[1]).
    it.second -> int: Represents the edge weight between u and it.first.

Inside main() Function
    u, v, w -> int: Stores input values representing an edge between nodes u and v with weight w.
*/

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // u, v are vertices and w is weight
        adjM[u].push_back({v, w}); // Since it is an undirected graph
        adjM[v].push_back({u, w}); // Since it is an undirected graph
    }
    primsMST(0);
    cout << cost;
    return 0;
}


// //Intput 
//4 5
// 0 1 10 
// 1 2 15
// 0 2 5
// 3 1 2
// 3 2 40
////Output
// 0 -1 0
// 2 0 5
// 1 0 10
// 3 1 2
// 17