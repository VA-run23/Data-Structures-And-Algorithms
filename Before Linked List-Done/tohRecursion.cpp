//Done
///IMPORTANT:
//TC : O(2^n)
#include <bits/stdc++.h>
using namespace std;
////source to helper to destination 
void towerOfHanoi(int n, char src, char dest, char helper){
    if(n==0){
        return ;
    }///THE MAIN LOGIC IS :  BIGGER THING CANNOT BE ON THE SMALLER ONE.
    towerOfHanoi(n-1, src, helper, dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1, helper, dest, src);

    
}
int main(){
    int n;
    cout<<"ENter the number of of disks"<<endl;
    cin>>n;
    towerOfHanoi(n, 'A', 'C', 'B');////A, B and C are the towers on which discs are placed
    //Initially a is the source , B is the helper and C is the destination 
return 0;
}
/*
Explanation of why we cannot apply Dynamic Programming (DP) to the Tower of Hanoi problem:

1. **Nature of the Problem:**
   - The Tower of Hanoi problem is inherently recursive and follows a divide-and-conquer approach.
   - The problem involves moving `n` disks from a source peg to a destination peg using a helper peg, with the constraint that a larger disk cannot be placed on top of a smaller disk.

2. **Exponential Time Complexity:**
   - The time complexity of the Tower of Hanoi problem is O(2^n) due to the recursive nature of the solution.
   - Each move sequence is unique and depends on the previous state of the disks, which means there isn't much room for reusing intermediate results.

3. **Lack of Overlapping Subproblems:**
   - Dynamic programming is most effective for problems with overlapping subproblems and optimal substructure.
   - In the Tower of Hanoi problem, each subproblem (move sequence) is unique and does not overlap with other subproblems.
   - There are no redundant calculations that can be avoided by storing intermediate results.

4. **Optimal Substructure:**
   - Although the problem exhibits optimal substructure (i.e., the solution to the problem can be constructed from solutions to subproblems), the subproblems are not independent and do not overlap.
   - Each move sequence must be executed in a specific order, making it difficult to apply memoization or tabulation.

5. **Recursive Dependency:**
   - The recursive calls in the Tower of Hanoi problem are heavily dependent on each other.
   - The sequence of moves requires solving subproblems in a specific order, and each move builds upon the previous state.

6. **Memoization Limitation:**
   - Memoization or tabulation techniques in DP are used to store intermediate results to avoid redundant calculations.
   - In the Tower of Hanoi problem, each subproblem is unique and there are no repeated calculations that can be memoized effectively.

Therefore, while dynamic programming is a powerful tool for certain classes of problems, it does not offer any meaningful advantages for the Tower of Hanoi problem. 
The recursive approach remains the most efficient and straightforward solution for this classic puzzle.
*/
