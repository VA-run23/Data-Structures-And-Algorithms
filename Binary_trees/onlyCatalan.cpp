//Done
// 28.6
//Combinatorics
// Catalan Numbers: Count specific combinatorial structures.
// Combinations: Count ways to select items without regard to order.
// Permutations: Count ways to arrange items in a specific order.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int catalan(int n)
{ // TC: ??
    if (n <= 1)
    { // as c(0) = 1  and c(1) = 1
        return 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catalan(i) * catalan(n - i - 1);
    }
    return res;
}

int main()
{
    for (int i = 0; i < 25; i++)
    {
        cout << catalan(i) << " ";
    }
    cout << endl;

    return 0;
}
