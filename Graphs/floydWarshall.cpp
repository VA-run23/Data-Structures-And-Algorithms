//TC: O(n^3)
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    vector<vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    int n = graph.size();
    vector<vector<int>> dist = graph;
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][j] == INF){
                cout << "INF" << " ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout<<dist[1][3]<<endl;
    cout<<dist[0][3]<<endl;
    return 0;
}



    // (0) --5--> (1)
    //  |         / |
    // 10       3   |
    //  |     /     |
    // (3) <-1-- (2)
