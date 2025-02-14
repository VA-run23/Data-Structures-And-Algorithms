/* Optimal substructure
Optimal substructure is a property of a problem 
that allows it to be broken down into smaller subproblems, 
which can be solved independently. The overall optimal solution 
can then be constructed from these optimal subproblem solutions. 
This property is essential for the application of dynamic programming.
*/


/* Memoization
Memoization is a technique used to store the results of expensive function calls 
and reuse them when the same inputs occur again. This helps to avoid redundant 
computations and improve the efficiency of algorithms. It's particularly useful 
in dynamic programming to handle overlapping subproblems by saving their results 
for future use.
*/


/*  Iterative 
The dynamic programming approach combines the iterative method with memoization 
to store the results of subproblems. This approach prevents redundant computations 
and ensures optimal performance by building up the solution iteratively 
while using a table to store intermediate results.
*/


// Recursive Approach (without memoization):
/*
The recursive approach breaks the problem into smaller subproblems but often 
results in redundant computations due to lack of memoization, leading to inefficiency.
*/

// Iterative Approach (using loops):
/*
The iterative approach uses loops instead of recursion to solve the problem,
avoiding recursive function call overhead and making the code more efficient 
and easier to understand for problems like computing the Fibonacci sequence.
*/

// Dynamic Programming (iterative with memoization):
/*
Dynamic programming combines the iterative approach with memoization, 
storing the results of subproblems to prevent redundant computations 
and ensuring optimal performance by iteratively building up the solution 
using a table to store intermediate results.
*/


// void* memset(void* ptr, int value, size_t num);

// ptr: Pointer to the block of memory to fill.
// value: The value to be set. This value is passed as an int, but the function fills the memory block with its unsigned char conversion.
// num: Number of bytes to be set to the value.




////Tabulation vs Memoization
/*
Memoization is a top-down, recursive approach that stores subproblem results to avoid redundant calculations. 
Tabulation is a bottom-up, iterative approach that builds solutions systematically using stored results. 
Both techniques aim to optimize computation by handling overlapping subproblems efficiently.
*/

/*
Tabulation is systematic memoization. 
While memoization is top-down and recursive, 
tabulation is bottom-up and iterative, 
both aim to optimize computation by storing subproblem results.
*/





////SUMMARY

// Method	Time Complexity
// Recursive Approach (without memoization)------------------------O(2^n)
// Iterative Approach (using loops)--------------------------------O(n)
// Dynamic Programming (iterative with memoization)----------------O(n * m)


// //PIONTS to remember
// Recursive Approach (without memoization): Exponential time complexity due to redundant computations.
// Iterative Approach (using loops): Linear time complexity, efficient for problems like the Fibonacci sequence.
// Dynamic Programming (iterative with memoization): Polynomial time complexity, optimal performance by storing subproblem results.




In cases where only one of the properties (overlapping subproblems or optimal substructure) is satisfied, the problem may still be solvable using different techniques, but dynamic programming may not be the most efficient approach. Let's break down what happens when one property is missing:

Overlapping Subproblems Not Satisfied
If a problem does not have overlapping subproblems, then each subproblem is independent, and there is no need to recompute the same subproblem multiple times. In this case, dynamic programming would not provide any advantage, and a direct recursive or divide-and-conquer approach would be more appropriate. An example is the merge sort algorithm, which does not benefit from memoization since each subproblem is unique and does not overlap with others.

Optimal Substructure Not Satisfied
If a problem does not exhibit optimal substructure, the optimal solution to the entire problem cannot be constructed from the optimal solutions to its subproblems. This means that even if you solve smaller subproblems optimally, it does not guarantee an optimal solution for the original problem. In such cases, techniques like greedy algorithms or heuristics might be more suitable. An example is the traveling salesman problem, where local optimal choices do not necessarily lead to a global optimum.

In summary, when one of these properties is not satisfied, alternative problem-solving techniques like greedy algorithms, divide-and-conquer, or heuristics may be more appropriate. Each problem requires careful analysis to determine the most effective approach. If you have a specific problem in mind, feel free to share it, and I can help you explore suitable techniques!