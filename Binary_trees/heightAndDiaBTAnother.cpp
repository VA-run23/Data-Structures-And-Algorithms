//Done
//27.7.2
////Time complexity to calculate Height of the tree: O(n)
//Diameter : Number of nodes in the longest path between any 2 levels
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data; 
    struct Node* left; 
    struct Node* right;

    Node(int val){
        data = val; 
        left = NULL; 
        right = NULL;
    }
};


int calcDiaOptimized(Node* root, int* height){
    if(root == NULL){
        *height = 0; 
        return 0;
    }
    int lh = 0, rh = 0;
    int lDia = calcDiaOptimized(root->left, &lh);
    int rDia = calcDiaOptimized(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1; // *height is updated to the maximum height of the left and right subtrees plus 1
    // *height acts as *lh and *rh in the recursive calls, storing the height of the current subtree
    return max(currDiameter, max(lDia, rDia));
    /*
    This line returns the maximum diameter of the current subtree:
    - `currDiameter` is the sum of the heights of the left and right subtrees plus one.
    - `lDia` and `rDia` are the diameters of the left and right subtrees.
    - The `max` function ensures the largest diameter found in the subtree is returned.
    - This recursive comparison helps calculate the diameter of the entire tree.
    */
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //         1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7

    // Calculate diameter optimized
    int height = 0;
    cout << calcDiaOptimized(root, &height) << " "; // Time complexity: O(n)
    return 0;
}
