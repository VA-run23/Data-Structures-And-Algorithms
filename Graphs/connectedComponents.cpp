//34.9
//Error
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

vector<bool> vis;
int n, m;
vvi adj;
vi components;

int get_comp(int idx){
    if(vis[idx]){
        return 0;
    }
    vis[idx] = true;
    int ans = 1;
    for(auto i : adj[idx]){//traversing to neighbours
        if(!vis[i]){
            ans += get_comp(i);
        }
    }
    return ans;
}

int main(){
    cin >> n >> m;
    adj = vvi(n);
    vis = vector<bool>(n, false);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); //u->v
        adj[v].push_back(u);//v->u

    }

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            components.push_back(get_comp(i));
        }
    }

    // Output the sizes of the connected components
    // for(auto size : components){
    //     cout << size << " ";//size of each component
    // }

    long long ans = 0;
 for(auto i: components){
    ans += (long long)i * (i - 1) / 2;
}
cout << ans << endl;

    //exampld
    //2 3
    //3 2
    //both are considered so divide it
    

    return 0;
}


// //Input
// 5 3
// 0 1 
// 2 3 
// 0 4
// //Output
// 3 2