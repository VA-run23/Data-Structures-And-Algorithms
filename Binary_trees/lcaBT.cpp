//DOne
//Time complexity: O(n)
////assuming all values in binary tree is positive
//LCA: Lowest common ancestor
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

bool getPath(Node* root, int key, vector<int> &path) {
    if (root == NULL) {
        return false;
    }

    path.push_back(root->data); // Add the current node's data to the path

    if (root->data == key) {
        return true; // If the current node is the key, return true
    }

    // Recursively check the left and right subtrees
    if (getPath(root->left, key, path) || getPath(root->right, key, path)) {
        return true;
    }

    path.pop_back(); // Remove the current node's data from the path if key is not found
    return false;
}

int LCA(Node* root, int n1, int n2) {
    vector<int> path1, path2;

    // Get paths from root to n1 and root to n2
    if (!getPath(root, n1, path1) || !getPath(root, n2, path2)) {
        return -1; // If either n1 or n2 is not present, return -1
        //ie. If the node itself is not there in the tree how can you find the LCA
    }

    int pc; // Path change index
    for (pc = 0; pc < path1.size() && pc < path2.size(); pc++) {
        //The condition pc < path1.size() && pc < path2.size() ensures that the loop iterates until pc is less than the size of the shorter path. This prevents the loop from going out of bounds of either path1 or path2
        if (path1[pc] != path2[pc]) {
            break; // Identify Divergence: When the nodes at the current index differ, the loop breaks.
        }
    }

    return path1[pc - 1]; \
    // The last common node before the paths diverge is the LCA.
}



Node* LCA2(Node* root, int n2, int n1) {
    // Base Case: If the root is NULL, there is no tree to search
    if (root == NULL) {
        return NULL;
    }

    // If either n1 or n2 matches the root's data, return root (one of the nodes has been found)
    if (root->data == n1 || root->data == n2) { 
        return root;
    }

    // Recur for the left and right subtrees
    Node* leftLCA = LCA2(root->left, n2, n1);
    Node* rightLCA = LCA2(root->right, n2, n1);

    // If both left and right subtrees have one of the nodes, the current node is the LCA
    if (leftLCA && rightLCA) { 
        // This checks in such a way that for every left node, its right subtree's node is checked and vice versa
        return root;
    }

    // Otherwise, check if left subtree or right subtree is LCA
    if (leftLCA != NULL) {
        return leftLCA;
    }
    return rightLCA;
}


int main(){
    struct Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->right->right= new Node(6);
    root->right->left= new Node(5);
    root->right->left->left= new Node(7);
      /*
               1
             /  \
            2    3
           /    / \
          4    5   6
              /
             7
     */
    //Input 1
    int lca= LCA(root, 4, 5);//LCA of 4 and 5 is 1
    if(lca== -1){
        cout<<"LCA doesn't exist"<<endl;
    }else{
        cout<<"LCA : " <<lca<<endl;
    }

    int n1=7, n2=6;
    Node* lca2= LCA2(root, n1, n2);
    if(lca2==NULL){
        cout<<"LCA doesn't exist"<<endl;
    }else{
        cout<<"LCA : " <<lca2->data<<endl;
    }
    return 0;
}
//Output:
//LCA : 1
//LCA : 3