//34.18
\//Solving by BFS
//Snake and Ladder Problem
//TC: 

//Given that the number of ladders and snakes
//First value for dice is the ladder starting point and the second value is the ending point
//First value for dice is the snake starting point and the second value is the ending point
//We have to find the minimum number of dice throws to reach the destination(starting point is 0 and destination is 100)

//Idea
// 1. BFS!
// 2. Push 1 into the queue,
//     For all possibilities in the dice:
//         Check if the next position is ladder, snake or empty.
//         Mark the square as visited and push into queue.
// 3. Stop the traversal, when you reached 100,
// 4. Return the number of dice throws.
#include <bits/stdc++.h>
using namespace std;


int main(){
    int ladders, snakes;
    cin>>ladders;
    map<int, int> lad;

    map<int, int> snak;
    for(int i=0; i<ladders; i++){
        int u, v;
        cin>>u>>v;
        lad[u] = v;
    }
    cin>>snakes;
    for(int i=0; i<snakes; i++){
        int u, v;
        cin>>u>>v;
        snak[u] = v;
    }
    int moves = 0;
    queue<int> q;
    q.push(1);
    bool found = false;
    vector<int> vis(101, 0);
    while(!q.empty() and !found){
        int sz = q.size();
        while(sz--){
            int t = q.front();
            q.pop();
            for(int die  =1; die<=6; die++){
                if(t + die == 100){
                    found = true;
                    break;
                } if(t + die <= 100 and lad[t+die] and !vis[lad[t+die]]){
                    vis[lad[t+die]] = 1;
                    if(lad[t+die] == 100){
                        found = true;
                        break;
                    }
                    q.push(lad[t+die]);
                } else if(t + die <= 100 and snak[t+die] and !vis[snak[t+die]]){
                    vis[snak[t+die]] = 1;
                    if(snak[t+die] == 100){
                        found = true;
                        break;
                    }
                    q.push(snak[t+die]);        
                } else if(t + die <= 100 and !vis[t+die] and !lad[t+die] and !snak[t+die]){
                    vis[t+die] = 1;
                    q.push(t+die);
                }

            }
        }
        moves++;
    }
    if(found){
        cout<<moves<<endl;
    } else {
        cout<<-1<<endl;
    }

    return 0;
}
// //Input
// 2
// 3 90
// 56 76 
// 3
// 99 10
// 30 20
// 20 5
// //Output
// 3