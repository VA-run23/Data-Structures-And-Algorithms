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


int maxPathSumUtil(Node* root, int &ans){
    if(root== NULL){
        return 0;
    }
    int left= maxPathSumUtil(root->left, ans);//stroring the left path sum at each level(as in case of recursion)
    int right= maxPathSumUtil(root->right, ans);//similarly storing the right path sum at each level(as in case of recursion)
    int nodeMax= max(max(root->data, root->data+ left+ right), 
                    max(root->data+ left, root->data+ right));////hame aise path include karna hai jaha ancestors include ho sake
    // There can be four cases for the maximum path:(The above line manages to choose the maximum of these four cases)
    // The value of the current node by itself.
    // The value of the current node with both left and right subtrees.
    // The value of the current node with the left subtree.
    // The value of the current node with the right subtree.

    ans= max(ans, nodeMax);
    int singlePathSUm= max(root->data, max(root->data + left , root->data + right));//here we are include the sum which gives maximum of current node with its left or right child
    return singlePathSUm;//this is returned to the parent node(like value 7 is returned from node with value 2 to root node)
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