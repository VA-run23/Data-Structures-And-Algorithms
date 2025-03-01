//Done
//TC: O(n)
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


int maxPathSumUtil(Node* root, int &ans) {
    if (root == NULL) {
        return 0;
    }

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    // Calculate the maximum sum for the current node including its left and right children
    // There can be four cases for the maximum path:
    // 1. The value of the current node by itself.
    // 2. The value of the current node with both left and right subtrees.
    // 3. The value of the current node with the left subtree.
    // 4. The value of the current node with the right subtree.
    int nodeMax = max(max(root->data, root->data + left + right), 
                      max(root->data + left, root->data + right));
    
    // nodeMax is used to determine the maximum path sum including the current node 
    // and its potential connections to both subtrees.

    ans = max(ans, nodeMax);

    // Calculate the maximum sum path considering the current node and one of its subtrees
    // This is the value that will be returned to the parent node, ensuring that only one subtree is included in the path
    int singlePathSum = max(root->data, max(root->data + left, root->data + right));

    // singlePathSum is used to ensure that the maximum path sum passed to the parent node 
    // includes the current node and only one of its subtrees, thereby preventing cycles 
    // and maintaining the tree structure.

    return singlePathSum; // this is returned to the parent node (like value 7 is returned from node with value 2 to root node)
}



int maxPathSum(Node* root){
    int ans= INT_MIN;
    maxPathSumUtil(root, ans);//recursively traverse each node
    return ans;


}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    /*
             1
           /  \
          2    3
         / \  / \
        4   5 6  7
   */

    cout<<maxPathSum(root);
    return 0;
}


//Output: 18

////This makes the value 18
// ///          1
//            /  \
//           2    3
//            \    \
//             5    7