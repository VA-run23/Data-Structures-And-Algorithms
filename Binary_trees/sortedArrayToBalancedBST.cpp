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

void preorderPrint(Node* root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);

}

Node* sortedArrToBST(int arr[], int start, int end){
    if(start > end){
        return NULL;
    }
    int mid= (start+ end)/2;

    Node* root = new Node(arr[mid]);

    root->left = sortedArrToBST(arr, start, mid-1);
    root->right = sortedArrToBST(arr, mid+ 1, end);
    return  root;
}

int main(){
    int arr[] ={10, 20 ,  30 , 40 , 50};
    Node* root = sortedArrToBST(arr, 0, 4);//4 is the n-1 value
    preorderPrint(root);
    cout<<endl;
    return 0;
}   






////Both are valid BST
//        3
//      /  \
//     2    4
//    /      \
//   1        5




//        3
//      /  \
//     1    4
//     \      \
//      2        5
