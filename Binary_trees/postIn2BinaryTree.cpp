//
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


int search(int inOrder[], int start, int end, int val){
    for(int i=start; i<=end; i++){
        if(inOrder[i]==val){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int postOrder[], int inOrder[], int start, int end){
    static int idx=4;//as n=5 in this case
    if(start>end){
        return NULL;
    }
    int val=postOrder[idx];
    idx--;
    Node* curr = new Node(val);
    if(start== end){
        return curr;
    }
    int pos= search(inOrder, start, end, val);
    curr->right= buildTree(postOrder, inOrder, pos+1, end);
    curr->left= buildTree(postOrder, inOrder, start, pos-1);
    return curr;
}

void inOrderPrint(Node* root){
    if(root == NULL){
        return ;
    }
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);

}

int main(){

    int postOrder[]={4, 2, 5, 3,1};
    int inOrder[]={4,2,1,5 ,3};

    Node* root= buildTree(postOrder, inOrder, 0, 4);
    inOrderPrint(root);
    cout<<"\n";
    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// // Define the structure for a Node in the binary tree
// struct Node {
//     int data; // Data stored in the node
//     struct Node* left; // Pointer to the left child
//     struct Node* right; // Pointer to the right child

//     // Constructor to initialize a new node
//     Node(int val) {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// // Function to search for a value in the inOrder array
// int search(int inOrder[], int start, int end, int val) {
//     for (int i = start; i <= end; i++) {
//         if (inOrder[i] == val) {
//             return i; // Return the index if the value is found
//         }
//     }
//     return -1; // Return -1 if the value is not found
// }

// // Function to build the binary tree from postOrder and inOrder arrays
// Node* buildTree(int postOrder[], int inOrder[], int start, int end) {
//     static int idx = 4; // Static index to keep track of the current element in postOrder array
//     if (start > end) {
//         return NULL; // Base case: if start index is greater than end index, return NULL
//     }
//     int val = postOrder[idx]; // Get the current value from postOrder array
//     idx--; // Decrement the index
//     Node* curr = new Node(val); // Create a new node with the current value
//     if (start == end) {
//         return curr; // If start and end are the same, return the current node
//     }
//     int pos = search(inOrder, start, end, val); // Find the position of the current value in inOrder array
//     curr->right = buildTree(postOrder, inOrder, pos + 1, end); // Recursively build the right subtree
//     curr->left = buildTree(postOrder, inOrder, start, pos - 1); // Recursively build the left subtree
//     return curr; // Return the current node
// }

// // Function to print the inOrder traversal of the binary tree
// void inOrderPrint(Node* root) {
//     if (root == NULL) {
//         return; // Base case: if the node is NULL, return
//     }
//     inOrderPrint(root->left); // Recursively print the left subtree
//     cout << root->data << " "; // Print the data of the current node
//     inOrderPrint(root->right); // Recursively print the right subtree
// }

// int main() {
//     int postOrder[] = {4, 2, 5, 3, 1}; // PostOrder traversal array
//     int inOrder[] = {4, 2, 1, 5, 3}; // InOrder traversal array

//     Node* root = buildTree(postOrder, inOrder, 0, 4); // Build the binary tree
//     inOrderPrint(root); // Print the inOrder traversal of the binary tree
//     cout << "\n"; // Print a newline
//     return 0; // Return 0 to indicate successful execution
// }
