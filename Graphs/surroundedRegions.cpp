

/*
Given a 2D board of characters, where each cell is either 'X' or 'O',
write a program to capture all regions surrounded by 'X'. A region is
captured by flipping all 'O's into 'X's in that region. A region is
considered surrounded if it is completely enclosed by 'X' on all four
sides. If an 'O' is on the border or connected to an 'O' on the border,
it cannot be fully surrounded by 'X' and should remain as 'O'.
*/

#include <bits/stdc++.h>
using namespace std;

void change(vector<vector<char>> &A, int x, int y){
    A[x][y] =  '*';
    int dx[]  = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    for(int i = 0; i < 4; i++){
        int cx = x + dx[i]; // cx and cy are its neighbours
        int cy = y + dy[i];
        if(cx >= 0 && cx < A.size() && cy >= 0 && cy < A[0].size() && A[cx][cy] == 'O'){
            change(A, cx, cy);
        }
    }
}

int main(){
    int n, m; 
    cin >> n >> m;
    vector<vector<char>> A(n, vector<char>(m)); // A is board
    for(int i = 0; i < n; i++){ // for loop to take input of board
        for(int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < n; i++){ // convert existing 'O' to '*'
        for(int j = 0; j < m; j++){
            if(A[i][j] == 'O'){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    change(A, i, j);
                }
            }
        }
    }
    for(int i = 0; i < n; i++){ // Capture: convert all 'O' to 'X'
        for(int j = 0; j < m; j++){
            if(A[i][j] == 'O'){
                A[i][j] = 'X';
            }
        }
    }
    for(int i = 0; i < n; i++){ // convert all '*' to 'O'
        for(int j = 0; j < m; j++){
            if(A[i][j] == '*'){
                A[i][j] = 'O';
            }
        }
    }
    for(int i = 0; i < n; i++){ // print the board
        for(int j = 0; j < m; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// // Input
// 4 4
// X X X X 
// X O O X 
// X X O X
// X O X X 

// // Output
// X X X X 
// X X X X 
// X X X X 
// X O X X 


// // // Input
// 4 4 
// X X X X 
// X O O X 
// X O O X
// X X X X 

// // // Output
// X X X X
// X X X X
// X X X X
// X X X X