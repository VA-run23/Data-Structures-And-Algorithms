//Done
#include <bits/stdc++.h>
using namespace std;

int countPathMaze(int n , int i, int j){////i and j are start and end points
    if(i==n-1 &&j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    return countPathMaze(n, i+1, j)+countPathMaze(n, i, j+1); //Move right (i, j+1) and down (i+1, j), and sum the number of valid paths
}

int countPathMazeDia(int n , int i, int j){
    if(i==n-1 &&j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    //To Move right (i, j+1), down (i+1, j), and diagonally (i+1, j+1)
    return countPathMazeDia(n, i + 1, j) + countPathMazeDia(n, i, j + 1) + countPathMazeDia(n, i + 1, j + 1);
}
int main(){
    int n,i,j;
    cout<<"Enter one dimension of square maze and staring points"<<endl;
    cin>>n>>i>>j;
    cout<<"Number of paths without travelling diagonally: " <<countPathMaze(n,i,j)<<endl;
    cout<<"Number of paths including diagonal paths: "<<countPathMazeDia(n,i,j)<<endl;
    return 0;
}