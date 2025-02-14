//Done
//The overall time complexity is thus O(n^n) in the worst case, since the algorithm explores every possible configuration of placing n queens on an n x n board. This is a non-polynomial time complexity, showcasing the problem's inherent computational complexity.
// The N-Queens problem  have solutions for every N ≥ 4.

/*
1. Start in the leftmost column.
2. Place a queen in the current column and move to the next column.
3. Check if placing the queen in the current row is safe. If it is:
   - Place the queen and move to the next column.
   - If placing the queen in the current row is not safe, move it to the next row within the same column and check again.
4. If all queens are placed safely, return true.
5. If placing a queen leads to a solution, recursively place queens in the remaining columns.
6. If placing a queen in a column does not lead to a solution, remove the queen (backtrack) and try the next row.
7. If all rows and columns have been tried and no solution is found, return false.
*/

/*
To compare the efficiency of O(n^n) and O(n^2 * 2^n):

O(n^n):
This represents exponential growth where the base is n and the exponent is also n. The complexity grows extremely fast, making it impractical for large n.

O(n^2 * 2^n):
This also represents exponential growth but with a smaller base of 2 and an additional polynomial factor of n^2. While it still grows quickly, the growth rate is less aggressive compared to O(n^n).

Comparison
- For small values of n: Both complexities are manageable, but O(n^2 * 2^n) will typically perform better.
- For large values of n: O(n^n) grows exponentially much faster and becomes infeasible much sooner compared to O(n^2 * 2^n).

 Conclusion
O(n^2 * 2^n) is more efficient than O(n^n) for both small and large values of n.
In practical terms, for large problems, even O(n^2 * 2^n) can be too slow, but it is significantly better than O(n^n).
*/


#include <bits/stdc++.h>
using namespace std;

bool isSafe(int** arr, int x, int y, int n){
    // Check for queens in the same column
    for(int row = 0; row < x; row++){
        if(arr[row][y])
            return false; // returns false if a queen is already placed in the same column
    }
    // Check for queens in the principle diagonal
    int row = x;
    int col = y;
    while(row >= 0 && col >= 0){
        if(arr[row][col] == 1){
            return false;
        }
        row--;
        col--;
    }
    // Check for queens in the reverse diagonal
    row = x;
    col = y;
    while(row >= 0 && col < n){
        if(arr[row][col] == 1){
            return false;
        }
        row--;
        col++;
    }
    return true;
}

// Function to solve the n-Queens problem using backtracking
bool nQueen(int** arr, int x, int n){
    // Base case: If all queens are placed
    if(x >= n){
        return true; // final solution found
    }
    // For each column in the current row, try placing the queen
    for(int col = 0; col < n; col++){
        if(isSafe(arr, x, col, n)){ // check if placing the queen is safe
            arr[x][col] = 1; // place the queen
            if(nQueen(arr, x + 1, n)){ // recursively place queens in the next row
                return true;
            }
            arr[x][col] = 0; // backtrack if placing the queen didn't lead to a solution
        }
    }
    return false; // return false if no solution is found
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
    if(nQueen(arr, 0, n)){//passing starting array, starting row and size of the board (number of rows ans columns)
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

//INPUT
// 8

////output
// 1 0 0 0 0 0 0 0
// 0 0 0 0 1 0 0 0
// 0 0 0 0 0 0 0 1
// 0 0 0 0 0 1 0 0
// 0 0 1 0 0 0 0 0
// 0 0 0 0 0 0 1 0
// 0 1 0 0 0 0 0 0
// 0 0 0 1 0 0 0 0