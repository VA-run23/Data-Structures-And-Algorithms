// Done
// isBalanced's time complexity: O(n^2): because the height of each node is calculated again and again 
// time complexity of height function : O(n)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){ // in c++ it is possible to create a constructor for a structure, unlike in c language
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(Node *root){
    // root is a traversing element
    // We are checking if it is the last node by checking if it is pointing to NULL
    if (root == NULL){
        return 0;
    }
    // Recursively reach the left-most node and calculate its height
    int lh = height(root->left);
    // Recursively reach the right-most node and compare its height with the left
    int rh = height(root->right);
    // Return the maximum height between left and right subtrees plus one for the current node
    return max(lh, rh) + 1;
}

// isBalanced() is used to traverse to the leaf node
bool isBalanced(Node *root){ // from main root node
    if (root == NULL){
        return true;
    }
    if (isBalanced(root->left) == false) { // this checks main root's left part
        return false;
    }if (isBalanced(root->right) == false){ // this checks main root's right part
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1){
        return true;
    }else{
        return false;
    }
}

int main(){
    // struct Node* root= new Node(1);
    // root->left= new Node(2);
    // root->right= new Node(3);
    // root->left->left= new Node(4);
    // root->left->right= new Node(5);
    // root->right->left= new Node(6);
    // root->right->right= new Node(7);


    //     1
    //    / \
    //   2   3
    //  / \ / \
    // 4  5 6  7

    // if(isBalanced(root)){
    //     cout<<"Balanced tree"<<"\n";
    // }else{
    //     cout<<"Unbalanced tree"<<endl;
    // }

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
    }else{
        cout << "Unbalanced tree" << endl;
    }
    return 0;
}
// Exactly right! When the program runs, the isBalanced function initiates first and makes recursive calls to check each subtree,
// effectively filling the call stack with these calls.
// It only calls the height function when it reaches nodes that need their heights calculated. This way,
// isBalanced first sets the stage for checking balance and then defers to height to measure the nodes' heights.

