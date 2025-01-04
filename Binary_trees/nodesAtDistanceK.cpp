//Do again
//two cases
//case1: Nodes at subtree
//case2: Nodes at ancestor

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
//case 1
void printSubTreeNodes(Node* root, int k){
    if(root == NULL ||  k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
    }
    printSubTreeNodes(root->left,  k-1);
    printSubTreeNodes(root->right,  k-1);
}



//case 2
int printNodesatK(Node* root, Node* target, int k){
    if(root== NULL){
        return -1; 
    }
    if(root == target){
        printSubTreeNodes(root,k );
        return 0;
    }
    int dl= printNodesatK(root->left,target, k);//finding target node in left subtree
    if(dl != -1){//dl is the distance in left subtree
        if(dl+1 == k){
            cout<<root->data<<" ";
        }else {
            printSubTreeNodes(root->right, k-dl -2);//-2 
        }
        return 1+dl;
    }

     int dr = printNodesatK(root->right,target, k);//finding target node in right subtree
    if(dr != -1){//dr is the distance in right subtree
        if(dr+1 == k){
            cout<<root->data<<" ";
        }else {
            printSubTreeNodes(root->left, k-dr -2);//The -2 accounts for moving up to the parent and then down the other subtree
        }
        return 1+dr;
    }
    return -1;
}

int main(){
    struct Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
      /*
               1
             /  \
            2    3
           / \  / \
          4   5 6  7
     */

    printNodesatK(root, root, 2);
    cout<<endl;
    printNodesatK(root, root, 1);
    cout<<endl;
    printNodesatK(root, root->left, 2);

    return 0;
}

////Output
// 4 5 6 7 
// 2 3 
// 3 

