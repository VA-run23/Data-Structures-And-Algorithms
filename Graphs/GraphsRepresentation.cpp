//34.3
//In this program you have to explictly mention the number of nodes  and edges, otherwise it won't work
//
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>//this forms 2D vector(matrix)
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) __builtin_popcount(x)

const int N = 1e5+2, MOD = 1e9+7;

//representation of graphs
vi adj[N];
int main(){
    int n, m;
    // in the context of the adjacency matrix, n represents the number of nodes (or vertices) in the graph. The matrix is of size (n+1) x (n+1) to accommodate node indices from 1 to n (assuming 1-based indexing). Each row and column in the matrix corresponds to a node in the graph
    cin>> n >> m;//n: number of nodes, m: number of edges
    vvi adjM(n+1, vi(n+1, 0));
    rep(i, 0, m){
        int x, y;//edge between x and yl
        cin>> x>> y;
        adjM[x][y] = 1;
        adjM[y][x] = 1;//These two lines create mutual connections
    }

    cout<<"Adjacency matrix of above graph is given by : "<<endl;
    rep(i, 1 , n+1){
        rep(j, 1, n+1){
            cout<<adjM[i][j]<<" ";
        }
        cout<<endl;
    }
////Second part from here
    //finding out edge between two nodes
    if(adjM[3][7] == 1){
        cout<<"THere is a edge between 3 and 7"<<endl;
    } else{
        cout<<"No edge"<<endl;
    }
    cout<<endl<<endl;

    cin>> n>> m;
        cout<<"Adjacency list of the above graph is given by : "<<endl;

    rep(i, 0, m){
        int x, y;
        cin>> x >> y;
        //pushing x in adjacency list of y and vice versa
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    rep(i, 1, n+1){
        cout<<i<<"->";
        for(int x: adj[i])//THis wont work in older versions
            cout<<x<<" ";
        cout<<endl;
    }
    

    return 0;
} 
// //Input
// 7 7 
// 1 2 
// 1 3 
// 2 4 
// 2 5
// 2 6
//  2 7
//  3 7

//  //Output
//  Adjacency matrix of above graph is given by : 
// 0 1 1 0 0 0 0 //Vertex 1:Connected to vertices 2 and 3.
// 1 0 0 1 1 1 1 //Vertex 2:Connected to vertices 1, 4, 5, 6, and 7.
// 1 0 0 0 0 0 1 //Vertex 3:Connected to vertices 1 and 7.
// 0 1 0 0 0 0 0 
// 0 1 0 0 0 0 0 
// 0 1 0 0 0 0 0 
// 0 1 1 0 0 0 0 

// Detailed Breakdown:
// Vertex 1:
// Connected to vertices 2 and 3.
// Row 1: 0 1 1 0 0 0 0
// Vertex 2:
// Connected to vertices 1, 4, 5, 6, and 7.
// Row 2: 1 0 0 1 1 1 1
// Vertex 3:
// Connected to vertices 1 and 7.
// Row 3: 1 0 0 0 0 0 1
// Vertex 4:
// Connected to vertex 2.
// Row 4: 0 1 0 0 0 0 0
// Vertex 5:
// Connected to vertex 2.
// Row 5: 0 1 0 0 0 0 0
// Vertex 6:
// Connected to vertex 2.
// Row 6: 0 1 0 0 0 0 0
// Vertex 7:
// Connected to vertices 2 and 3.
// Row 7: 0 1 1 0 0 0 0


// //INput
// 7  7
// 1 2 
// 1 3 
// 2 4 
// 2 5
// 2 6
//  2 7
//  3 7
// 7  7
// 1 2 
// 1 3 
// 2 4 
// 2 5
// 2 6
//  2 7
//  3 7

// //Output
// Adjacency matrix of above graph is given by : 
// 0 1 1 0 0 0 0 
// 1 0 0 1 1 1 1 
// 1 0 0 0 0 0 1 
// 0 1 0 0 0 0 0 
// 0 1 0 0 0 0 0 
// 0 1 0 0 0 0 0 
// 0 1 1 0 0 0 0 
// THere is a edge between 3 and 7


// Adjacency list of the above graph is given by : 
// 1->2 3 
// 2->1 4 5 6 7 
// 3->1 7 
// 4->2 
// 5->2 
// 6->2 
// 7->2 3 
