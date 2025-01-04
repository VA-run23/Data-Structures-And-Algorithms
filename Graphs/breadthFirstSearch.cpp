//34.4
//TC: O(m+n)
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
bool vis[N];//visited array
vi adj[N];
int main(){
    for(int i =0; i<N; i++){
        vis[i] =0;
    }
    int n, m; //Number of nodes and edges
    cin>> n>> m;
    int x, y;
    for(int i =0 ; i<m ; i++){
        cin>> x>> y;
        adj[x].push_back(y);
        adj[y].push_back(x); 
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<endl;
        
        for(int it: adj[node]){
            if(!vis[it]){
                vis[it]  = 1;
                q.push(it);
            }
        }
    }
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

// //output
// 1
// 2
// 3
// 4
// 5
// 6
// 7

