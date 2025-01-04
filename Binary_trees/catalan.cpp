// Done
// 28.6.2
////In this program we are finding number of valid BT structures for the elements provided
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

vector<Node*> constructTrees(int start, int end) {
    vector<Node *> trees; // Vector to store the root nodes of all possible BSTs within the range [start, end].
                          // Each entry in this vector is a complete BST formed by combining left and right subtrees.

    if (start > end) {
        trees.push_back(NULL); // Base case: if start is greater than end, add NULL to the vector and return.
        return trees;
    } 

    for (int i = start; i <= end; i++) { // Loop through all values from start to end, considering each as a root node.
        // Generate all possible left subtrees with values less than i.
        vector<Node*> leftSubtrees = constructTrees(start, i - 1);
        // Generate all possible right subtrees with values greater than i.
        vector<Node*> rightSubtrees = constructTrees(i + 1, end);


            //(after all recursive calls) Now we have all the values inside vector, we just have to combine in them with different root nodes(with the value of i) to make them different trees
        // Combine each left subtree with each right subtree to form the BSTs.
        for (int j = 0; j < leftSubtrees.size(); j++) {
            Node* left = leftSubtrees[j];
            for (int k = 0; k < rightSubtrees.size(); k++) {
                Node* right = rightSubtrees[k];
                Node* node = new Node(i); // Create a new root node with the current value i.
                node->left = left;        // Attach the left subtree.
                node->right = right;      // Attach the right subtree.
                trees.push_back(node);    // Add this newly formed tree to the vector.
            }
        }
    }
    return trees; // Return the vector containing all possible BSTs.
}


void preorderPrint(Node* root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main(){
    
    vector<Node*> totalTrees =  constructTrees(1,3);

   // vector<Node *> totalTrees = constructTrees(1, -3);//THIS DOESNOT WORK
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout<<(i+1)<<" : ";
        preorderPrint(totalTrees[i]);
        cout<<endl;
    }
    return 0;
}

//The result is a vector of Node *because the function returns all the possible binary trees as Node pointers.
//Each Node in the result represents the root of one possible tree.The result is a vector of Node *because the function returns 
//all the possible binary trees as Node pointers.Each Node in the result represents the root of one possible tree.
    // ////Output
    // 1 : 1 2 3
    // 2 : 1 3 2
    // 3 : 2 1 3
    // 4 : 3 1 2
    // 5 : 3 2 1

//     1
//      \
//       2
//        \
//         3

//     1
//      \
//       3
//      /
//     2

//     2
//    / \
//   1   3

//     3
//    /
//   1
//    \
//     2


//     3
//    /
//   2
//  /
// 1
