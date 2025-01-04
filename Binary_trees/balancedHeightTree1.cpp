
//Done
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

bool isBalanced(Node* root, int* height){

    if(root==NULL){
        return true;
    }
    int lh= 0, rh=0;
    if(isBalanced(root->left, &lh)== false){
        return false;
    }
    if(isBalanced(root->right, &rh)==false){
        return false;
    }
    *height=max(lh, rh)+1;//explain 
    if(abs(lh-rh)<=1){
        return true;
    } else {
        return false;
    }

}
int main(){
    int height=0;
    //Balanced tree
    struct Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);


    if(isBalanced(root,&height)){
        cout<<"Balanced tree"<<"\n";
    }else{
        cout<<"Unbalanced tree"<<endl;
    }



    // ////Unbalanced tree
    //   Node* root2=new Node(1);
    // root2->left= new Node(2);
    // root2->left->left= new Node(3);
    //     //     1
    //     //    /
    //     //   2
    //     //  /
    //     // 3

    //  if(isBalanced(root2, &height)){
    //     cout<<"Balanced tree"<<"\n";
    // }else{
    //     cout<<"Unbalanced tree"<<endl;
    // }


    return 0;
}


// 1. **Initial Call**:
//    - `isBalanced(root, &height)` is called with the root node (data = 1).
//    - `lh` and `rh` are initialized to 0.

// 2. **Left Subtree of Root**:
//    - `isBalanced(root->left, &lh)` is called with the left child of root (data = 2).
//    - Again, `lh` and `rh` are initialized to 0.

// 3. **Left Subtree of Node 2**:
//    - `isBalanced(root->left->left, &lh)` is called with the left child of node 2 (data = 4).
//    - Since node 4 is a leaf, `isBalanced(NULL, &lh)` returns true for both left and right children.
//    - `lh` and `rh` remain 0, so `*height` for node 4 is set to 1.

// 4. **Right Subtree of Node 2**:
//    - `isBalanced(root->left->right, &rh)` is called with the right child of node 2 (data = 5).
//    - Similar to node 4, `isBalanced(NULL, &rh)` returns true for both children.
//    - `lh` and `rh` remain 0, so `*height` for node 5 is set to 1.

// 5. **Back to Node 2**:
//    - `lh` and `rh` for node 2 are both 1 (from nodes 4 and 5).
//    - `*height` for node 2 is set to 2 (max(1, 1) + 1).
//    - Since `abs(lh - rh) <= 1`, node 2 is balanced.

// 6. **Right Subtree of Root**:
//    - `isBalanced(root->right, &rh)` is called with the right child of root (data = 3).
//    - Similar steps are followed for nodes 6 and 7 as for nodes 4 and 5.
//    - `*height` for node 3 is set to 2.

// 7. **Back to Root**:
//    - `lh` and `rh` for root are both 2 (from nodes 2 and 3).
//    - `*height` for root is set to 3 (max(2, 2) + 1).
//    - Since `abs(lh - rh) <= 1`, the root is balanced.

// This process ensures that each node's height is calculated and checked for balance recursively. If any subtree is unbalanced, the function returns false immediately.