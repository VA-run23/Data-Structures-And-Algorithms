//Done
//The overall time complexity is thus O(n^n) in the worst case, since the algorithm explores every possible configuration of placing n queens on an n x n board. This is a non-polynomial time complexity, showcasing the problem's inherent computational complexity.
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int** arr, int x, int y, int n){
    for(int row=0; row<x; row++){
        if(arr[row][y])
            return false;
    }
    int row=x;
    int col=y;
    while(row>=0 && col>=0){//principle diagonal
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }
    row=x;
    col=y;
    while(row>=0 && col<n){////reverse diagonal
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQueen(int** arr, int x, int n){////since only one queen can be placed in a row no need to check other columns of the same row,  so no need of int y
    if(x>=n){
        return true;
    }
    for(int col=0; col<n; col++){
        if(isSafe(arr, x, col, n)){
            arr[x][col]=1;
            if(nQueen(arr, x+1, n)){//this allow to check whether queen is placed in correct position or not, if not it backtracks. Thus it backtracks after reaching the last position to place the queen
                return true;
            }
            arr[x][col]=0;//backtracking
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int** arr =new int*[n];
    //int** arr: This declares a pointer to a pointer of integers. Essentially, it sets up a structure to hold addresses of integer arrays.
    //new int*[n];: This allocates memory for an array of n pointers to integers. So, each element of this array will eventually point to an array of integers (another array)
    //int** arr = new int*[n]; sets up a 2D array by creating an array of n pointers. Each pointer will eventually point to an array of integers.
    //arr[i] = new int[n]; takes one of those pointers and makes it point to an array of n integers.
    
    for(int i=0; i<n; i++){
        arr[i]=new int[n];
        for(int j=0; j<n; j++){
            arr[i][j]=0;
        }
    }
    if(nQueen(arr, 0, n)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
////output
// 8
// 1 0 0 0 0 0 0 0
// 0 0 0 0 1 0 0 0
// 0 0 0 0 0 0 0 1
// 0 0 0 0 0 1 0 0
// 0 0 1 0 0 0 0 0
// 0 0 0 0 0 0 1 0
// 0 1 0 0 0 0 0 0
// 0 0 0 1 0 0 0 0