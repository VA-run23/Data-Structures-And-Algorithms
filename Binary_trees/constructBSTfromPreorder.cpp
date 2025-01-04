//Done
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* constructBST(int preorder[], int& preorderIdx, int key, int min, int max, int n) {
    if (preorderIdx >= n) {//Key is the current value
        return NULL;
    }

    Node* root = NULL;
    if (key > min && key < max) {
        root = new Node(key);
        preorderIdx++; // Move to the next element in the preorder array
        // Construct the left subtree with the next element in the preorder array if it is within the valid range
        if (preorderIdx < n) {
            root->left = constructBST(preorder, preorderIdx, preorder[preorderIdx], min, key, n);
        }
        // Construct the right subtree with the next element in the preorder array if it is within the valid range
        if (preorderIdx < n) {
            root->right = constructBST(preorder, preorderIdx, preorder[preorderIdx], key, max, n);
        }
       // int preorder[] = {10, 2, 1, 13, 11};
        //there are two if conditions as if the ith element is forming the left subtree's part of the node, then we even also have to check if the (i+1)th element is forming the right subtree of the node by keeping in mind that it should be less than main node if in left subtree and similarly in right subtree, the left node should be more than the main rooot node
    }
    // The two if conditions ensure that the function checks both the left and right subtrees.
    // When constructing the left subtree, the function checks if the next element in the preorder array (i.e., the (i+1)th element) can be placed in the left subtree of the current node.
    // This is done by verifying that the element is within the valid range defined by the current node's value and the minimum value.
    // If the element is within this range, it is placed in the left subtree, and the function recursively constructs the left subtree with the next element in the preorder array.
    // Similarly, when constructing the right subtree, the function checks if the next element in the preorder array can be placed in the right subtree of the current node.
    // This is done by verifying that the element is within the valid range defined by the current node's value and the maximum value.
    // If the element is within this range, it is placed in the right subtree, and the function recursively constructs the right subtree with the next element in the preorder array.
    // By checking both conditions, the function ensures that each element is placed in the correct position in the BST, maintaining the BST properties.

    return root;
}

////time complexity: O(n) as preordeIdx is incrementing from 0 to n

void printPreorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5; // size
    int preorderIdx = 0;
    Node* root = constructBST(preorder, preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    printPreorder(root);
    //     10
    //     / \ 
    //    2  13
    //   /   /
    //  1   11
    return 0;
}

// constructBST(preorder, preorderIdx, 10, INT_MIN, INT_MAX, n) // preorderIdx = 0, key = 10
//     ├── constructBST(preorder, preorderIdx, 2, INT_MIN, 10, n) // preorderIdx = 1, key = 2 (left subtree of 10)
//     │   ├── constructBST(preorder, preorderIdx, 1, INT_MIN, 2, n) // preorderIdx = 2, key = 1 (left subtree of 2)
//     │   │   ├── constructBST(preorder, preorderIdx, 13, INT_MIN, 1, n)->NULL // preorderIdx = 3, key = 13 (left subtree of 1)
//     │   │   └── constructBST(preorder, preorderIdx, 13, 1, 2, n)->NULL // preorderIdx = 3, key = 13 (right subtree of 1)
//     │   └── constructBST(preorder, preorderIdx, 13, 2, 10, n)->NULL // preorderIdx = 3, key = 13 (right subtree of 2)
//     └── constructBST(preorder, preorderIdx, 13, 10, INT_MAX, n) // preorderIdx = 3, key = 13 (right subtree of 10)
//         ├── constructBST(preorder, preorderIdx, 11, 10, 13, n) // preorderIdx = 4, key = 11 (left subtree of 13)
//         │   ├── constructBST(preorder, preorderIdx, 11, 10, 11, n)->NULL // preorderIdx = 5, key = 11 (left subtree of 11)
//         │   └── constructBST(preorder, preorderIdx, 11, 11, 13, n)->NULL // preorderIdx = 5, key = 11 (right subtree of 11)
//         └── constructBST(preorder, preorderIdx, 11, 13, INT_MAX, n)->NULL // preorderIdx = 5, key = 11 (right subtree of 13)

//     // int preorder[] = {10, 2, 1, 13, 11};
