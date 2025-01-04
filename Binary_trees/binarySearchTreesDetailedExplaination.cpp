//Done
//time complexity reduces from O(n) to O(log n)
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

Node* insertBST(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insertBST(root->left, val);
        //though you are sending root->right or root->left in the recursive call, 
        //in the function call it is copied to root named variable only;  
        //but at the end root remains the  same one which is passed from the main function
    }else{
        //val>root->data
        root->right = insertBST(root->right, val);
    }
    return root;//returning the top level root
}

void inorder(Node* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root = NULL;
    // root = insertBST(root,5);
    // insertBST(root, 100);
    // insertBST(root, 1);
    // insertBST(root, 3);
    // insertBST(root, 4);
    // insertBST(root, 2);
    // insertBST(root, 7);
    // insertBST(root, 1); 


////Trial
    root = insertBST(root,10);
    insertBST(root, 4);
    insertBST(root, 100);
    insertBST(root, 6);
    insertBST(root, 5);
//      10
//    /  \
//   4   100
//    \
//     6
//    /
//   5

    cout << "Root data before inorder: " << root->data << endl; // The root, once assigned from NULL, does not change. Here, it is explicitly assigned the value 10.
    inorder(root);
    cout<<endl<<"Root data after inorder: "<<root->data<<endl;
    cout<<endl;
    return 0;
}