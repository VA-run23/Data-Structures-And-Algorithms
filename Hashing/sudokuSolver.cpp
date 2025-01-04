#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second 
#define setBits(x) __builtin_popcount(x)

// Helper function to solve the Sudoku
void helper(int r, int c, vector<vector<char>>& a, map<pair<int, int>, map<int, int>>& mp, vector<map<int, int>>& row, vector<map<int, int>>& col) {
    if (r == 9) {
        for (auto it : a) {
            for (auto i : it) {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;  // Adding return statement here
    }
    if (c == 9) {
        helper(r + 1, 0, a, mp, row, col);
        return;
    }
    if (a[r][c] != '.') {  // If not empty
        helper(r, c + 1, a, mp, row, col);
        return;
    }
    rep(i, 1, 10) {  // Loop through 1 to 9
        int rw = r / 3, cl = c / 3;
        if (!mp[{rw, cl}][i] && !row[r][i] && !col[c][i]) {
            mp[{rw, cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            a[r][c] = i + '0';
            helper(r, c + 1, a, mp, row, col);  // Passing 'a' in the recursive call

            // Backtracking
            mp[{rw, cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            a[r][c] = '.';
        }
    }
}

// Function to set up and solve the Sudoku
void solveSudoku(vector<vector<char>>& a) {
    map<pair<int, int>, map<int, int>> mp;
    //The map<pair<int, int>, map<int, int>> in your code is used to keep track of the numbers present in each 3x3 subgrid of the Sudoku board.
    // Key: pair<int, int> represents the coordinates of a 3x3 subgrid. For example, the top-left subgrid has coordinates (0, 0), the middle subgrid in the first row has coordinates (0, 1), and so on.
    // Value: map<int, int> keeps track of the numbers present in that specific 3x3 subgrid. The key in this inner map is the number (from 1 to 9), and the value is a flag (1 if the number is present, 0 otherwise).
    vector<map<int, int>> row(9);// to keep track of the numbers present in each row and each column of the Sudoku board
    vector<map<int, int>> col(9);
    int i, j;
    rep(i, 0, 9) {//iterate over each row
        rep(j, 0, 9) {//iterate over each column
            if (a[i][j] != '.') {
                mp[{i / 3, j / 3}][a[i][j] - '0'] = 1;//this is done for singe 3*3 block
              //mp<pair, pair>, map<int, 1>
                //For all combinations of i and j within the range 0 to 2, the subgrid coordinates will be {0, 0}. This means that all cells in the top-left 3x3 subgrid will be mapped to the same key {0, 0} in the mp map.
                row[i][a[i][j] - '0'] = 1;
                col[j][a[i][j] - '0'] = 1; 
            }
        }
    }
    helper(0, 0, a, mp, row, col);
}

int main() {
    vector<vector<char>> sudoku = {//2-D vector
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSudoku(sudoku);

    return 0;
}



////Output
// 5 3 4 6 7 8 9 1 2 
// 6 7 2 1 9 5 3 4 8 
// 1 9 8 3 4 2 5 6 7 
// 8 5 9 7 6 1 4 2 3 
// 4 2 6 8 5 3 7 9 1 
// 7 1 3 9 2 4 8 5 6 
// 9 6 1 5 3 7 2 8 4 
// 2 8 7 4 1 9 6 3 5 
// 3 4 5 2 8 6 1 7 9 



// Sure, let's break down each part of the code and understand what it does:

// ### `mp[{i / 3, j / 3}][a[i][j] - '0'] = 1`
// - **`i / 3` and `j / 3`**: These expressions determine which 3x3 subgrid the cell `(i, j)` belongs to. For example, cells `(0,0)` to `(2,2)` belong to the top-left subgrid `(0,0)`, cells `(3,3)` to `(5,5)` belong to the middle subgrid `(1,1)`, and so on.
// - **`a[i][j] - '0'`**: This converts the character at `a[i][j]` (which is a digit character like '1', '2', etc.) to its corresponding integer value. For example, `'5' - '0'` results in `5`.
// - **`mp[{i / 3, j / 3}][a[i][j] - '0'] = 1`**: This marks the presence of the number in the corresponding 3x3 subgrid by setting the value to `1`. The key `{i / 3, j / 3}` identifies the subgrid, and the inner key `a[i][j] - '0'` identifies the number.

// ### `row[i][a[i][j] - '0'] = 1`
// - **`row[i]`**: This accesses the map corresponding to the `i`-th row.
// - **`a[i][j] - '0'`**: Converts the character at `a[i][j]` to its integer value.
// - **`row[i][a[i][j] - '0'] = 1`**: This marks the presence of the number in the `i`-th row by setting the value to `1`.

// ### `col[j][a[i][j] - '0'] = 1`
// - **`col[j]`**: This accesses the map corresponding to the `j`-th column.
// - **`a[i][j] - '0'`**: Converts the character at `a[i][j]` to its integer value.
// - **`col[j][a[i][j] - '0'] = 1`**: This marks the presence of the number in the `j`-th column by setting the value to `1`.

// ### Summary
// These lines of code are used to initialize the tracking structures for the Sudoku solver:
// - **`mp`**: Tracks the presence of numbers in each 3x3 subgrid.
// - **`row`**: Tracks the presence of numbers in each row.
// - **`col`**: Tracks the presence of numbers in each column.

// By setting these values to `1`, the code ensures that the solver knows which numbers are already present in each row, column, and subgrid, which is crucial for checking the validity of placing new numbers during the solving process.

// Would you like to explore any other part of the code or have more questions?