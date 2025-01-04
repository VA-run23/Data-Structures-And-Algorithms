//Learn this

//Time complexity:
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

struct Info{
    int size;
    int max; 
    int min;
    int ans;
    bool isBST;
};

Info largestBSTinBT(Node* root){
    if(root == NULL){
        return {0, INT_MIN, INT_MAX, 0, true};//returning struct Info
    }
    if(root->left == NULL && root->right == NULL){//single node
        return {1, root->data, root->data, 1, true};//returning struct Info
    }

    Info leftInfo= largestBSTinBT(root->left);
    Info rightInfo= largestBSTinBT(root->right);

    Info curr;//a structure type variable curr
    curr.size = (1 + leftInfo.size + rightInfo.size);

    if (leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data) {
        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max =  max(rightInfo.max, max(leftInfo.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}

int main(){
    struct Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    cout<<"Largest BST in BT: "<<largestBSTinBT(root).ans<<endl;

    struct Node* root1= new Node(15);
    root1->left= new Node(20);
    root1->right= new Node(30);
    root1->left->left= new Node(5);
        //       15
        //     /  \
        //    20  30
        //   /
        //  5
    cout<<"Largest BST in BT: "<<largestBSTinBT(root1).ans<<endl;

    return 0;
} 