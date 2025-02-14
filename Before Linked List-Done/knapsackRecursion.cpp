//Done
//TC : O(2^n)
#include <bits/stdc++.h>
using namespace std;

int knapsack(int value[], int wt[], int n, int W){
    if(n==0 || W==0){
        return 0;
    }
    if(wt[n-1]>W){
        return knapsack(value, wt, n-1, W);
    }
    return max(knapsack(value, wt, n-1, W-wt[n-1])+value[n-1], knapsack(value, wt, n-1, W));
//     This line evaluates two scenarios:
// Including the current item, adding its value, and reducing the capacity accordingly.
// Excluding the current item.
// The function then returns the maximum value of these two scenarios, ensuring the optimal solution.
}

int main(){
    int wt[]={10, 20, 30};//wt and value are corresponding to each other
    int value[]={100, 50, 150};
    int W=50;
    cout<<knapsack(value,wt, 3,W)<<endl;
    return 0;
}
// //OUTPUT:
// 250
//This program puts restriction of W on wt to get maximum value