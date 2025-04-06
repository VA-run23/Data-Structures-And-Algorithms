///THIS: code is a C++ implementation of a recursive algorithm to count the number of paths in a maze from the top-left corner to the bottom-right corner.
//Done
/* Time Complexity for Original Version:
       countPathMaze: The time complexity is O(2^(2n)) in the worst case because every cell can lead to two recursive calls, leading to an exponential growth in the number of calls.
       
       countPathMazeDia: The time complexity is even higher, O(3^(2n)), due to the three recursive calls per cell.
    */
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
    //NOTE: Enter one dimension of square maze and staring points
   
    cin>>n>>i>>j;
    cout<<"Number of paths without travelling diagonally: " <<countPathMaze(n,i,j)<<endl;
    cout<<"Number of paths including diagonal paths: "<<countPathMazeDia(n,i,j)<<endl;
    return 0;
}
// // //INput
// 2 0 0 
// //Output
// Number of paths without travelling diagonally: 2
// Number of paths including diagonal paths: 3

/*Explanation of example 1:
Right → Down:

    Move from (0, 0) to (0, 1) (right).

    Move from (0, 1) to (1, 1) (down).

    Path: (0, 0) → (0, 1) → (1, 1).

Down → Right:

    Move from (0, 0) to (1, 0) (down).

    Move from (1, 0) to (1, 1) (right).

    Path: (0, 0) → (1, 0) → (1, 1).

Diagonal:

    Move from (0, 0) to (1, 1) (diagonal).

    Path: (0, 0) → (1, 1).

So, there are 3 paths when including diagonal movement.
*/


// // //INput
// 5 0 0 
// //Output
// Number of paths without travelling diagonally: 70
// Number of paths including diagonal paths: 321
