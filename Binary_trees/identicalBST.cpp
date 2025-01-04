//Done
//TC: O(n)
//

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

// is identical
bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true; // Both trees are empty, so they are identical
    }
    else if(root1 == NULL || root2 == NULL){
        return false; // One tree is empty and the other is not, so they are not identical
    }
    else{
        bool cond1 = root1->data == root2->data; // Check if the current nodes' data are equal
        bool cond2 = isIdentical(root1->left, root2->left); // Recursively check if the left subtrees are identical
        bool cond3 = isIdentical(root1->right, root2->right); // Recursively check if the right subtrees are identical
        return (cond1 && cond2 && cond3); // All conditions must be true for the trees to be identical
    }
}

int main(){
    struct Node* root1= new Node(1);
    root1->left= new Node(2);
    root1->right= new Node(3);
    root1->left->left= new Node(4);
    root1->left->right= new Node(5);
    root1->right->left= new Node(6);
    root1->right->right= new Node(7);

    struct Node* root2= new Node(1);
    root2->left= new Node(2);
    root2->right= new Node(3);
    root2->left->left= new Node(4);
    root2->left->right= new Node(5);
    root2->right->left= new Node(6);
    root2->right->right= new Node(3);
    cout<<isIdentical(root1, root2)  <<endl;
    cout<<isIdentical(root1, root1)  <<endl; 
      /*
               1
             /  \
            2    3
           / \  / \
          4   5 6  7
     */
    return 0;
}