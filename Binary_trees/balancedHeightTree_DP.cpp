/*
In the original implementation:
- `isBalanced` calls itself recursively for left and right subtrees.
- It also calls `height` for each node, which computes height recursively.
- This results in a time complexity of O(n^2).

In the optimized implementation:
- `isBalancedHelper` returns both balance status and height.
- Heights are calculated once and stored, avoiding redundant calculations.
- This reduces the time complexity to O(n).
- Using memoization, the optimized version calculates height only once per node.
*/


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Hashmap to store heights of nodes
unordered_map<Node*, int> heightMap;

int height(Node *root){
    if (root == NULL){
        return 0;
    }
    // If the height of this node is already calculated, return it
    if (heightMap.find(root) != heightMap.end()){
        return heightMap[root];
    }
    int lh = height(root->left);
    int rh = height(root->right);
    // Store the calculated height in the hashmap
    heightMap[root] = max(lh, rh) + 1;
    return heightMap[root];
}

bool isBalanced(Node *root){
    if (root == NULL){
        return true;
    }
    if (isBalanced(root->left) == false){
        return false;
    }
    if (isBalanced(root->right) == false){
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1){
        return true;
    } else {
        return false;
    }
}

int main(){
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);
    //     1
    //    /
    //   2
    //  /
    // 3

    if (isBalanced(root2)){
        cout << "Balanced tree" << "\n";
    } else {
        cout << "Unbalanced tree" << endl;
    }
    return 0;
}
