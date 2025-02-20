//Detailed explanation below

//28.4
//Time comlpexity: O(n)
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data; 
    struct Node* left; 
    struct Node* right;

    Node(int val){
        data= val; 
        left=NULL; 
        right =NULL;
    }
};

//check for BST
bool isBST(Node* root, Node* min, Node* max){//min and max are of node pointer type so that we can pass the node(root) itself in next levels

    if(root == NULL){
        return true;
    }

    if(min != NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL && root->data >= max->data){
        return false;
    }

    bool leftValid = isBST(root->left, min, root);//passing parameters to set boundaries for the left subtree and right subtree
    bool rightValid = isBST(root->right ,  root, max);//
    return leftValid && rightValid;
}

int main (){
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right  = new Node(6);
    if(isBST(root, NULL, NULL)){
        cout<<"Valid BST"<<endl;
    }else{
        cout<<"Invalid BST"<<endl;
    }


    //     Node* root = new Node(5);
    // root->left = new Node(2);
    // root->right  = new Node(6);
    // root->left->left = new Node(5);
    // root->right->right = new Node(0);
    // if(isBST(root, NULL, NULL)){
    //     cout<<"Valid BST"<<endl;
    // }else{
    //     cout<<"Invalid BST"<<endl;
    // }


    // root->right  = new Node(3);
    // if(isBST(root, NULL, NULL)){
    //     cout<<"Valid BST"<<endl;
    // }else{
    //     cout<<"Invalid BST"<<endl;
    // }


}
// //OUtput
// Valid BST
// Invalid BST
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// if a left child has two nodes then: bool leftValid = isBST(root->left, min, root);: min remains Null and root will be the current node;
// similarly for bool rightValid = isBST(root->right , root, max); : root is the current node and max will be Null, right?
// Yes, you're mostly correct. Let's break it down with an example to clarify the details for both the left and right subtrees, particularly focusing on the values of `min` and `max`.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Left Subtree: For the left child:

/*
bool leftValid = isBST(root->left, min, root);
// Here, min remains NULL, and root is the current node.
*/
// min remains NULL because there's no lower boundary constraint for the left subtree.
// root becomes the max boundary for the left subtree.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Example:
// Consider the subtree rooted at node with value 5, having a left child 2 with two children:

//       5
//      / 
//     2   
//    / \
//   1   3

// When calling isBST for node 2:
/*
isBST(root->left, NULL, 5); // min = NULL, max = 5
*/
// For node 2, min is NULL and max is 5.

// Further calls for node 2:
// Left child (1):
/*
isBST(node2->left, NULL, node2); // min = NULL, max = 2
*/
// For node 1, min is NULL and max is 2.
// Right child (3):
/*
isBST(node2->right, node2, 5); // min = 2, max = 5
*/
// For node 3, min is 2 and max is 5.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Right Subtree: For the right child:

/*
bool rightValid = isBST(root->right, root, max);
// Here, root is the current node, and max remains NULL.
*/
// root becomes the min boundary for the right subtree.
// max remains NULL because there's no upper boundary constraint for the right subtree.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Example:
// Consider the subtree rooted at node with value 5, having a right child 6 with two children:

//     5
//      \
//       6
//      / \
//     4   7

// When calling isBST for node 6:
/*
isBST(root->right, 5, NULL); // min = 5, max = NULL
*/
// For node 6, min is 5 and max is NULL.

// Further calls for node 6:
// Left child (4):
/*
isBST(node6->left, 5, node6); // min = 5, max = 6
*/
// For node 4, min is 5 and max is 6.
// Right child (7):
/*
isBST(node6->right, node6, NULL); // min = 6, max = NULL
*/
// For node 7, min is 6 and max is NULL.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Summary:
// For the left subtree, min remains NULL and root (current node) becomes the max.
// For the right subtree, root (current node) becomes the min and max remains NULL.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Your understanding is accurate, and these boundary constraints ensure that each node adheres to the Binary Search Tree (BST) properties. Nice work!
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
