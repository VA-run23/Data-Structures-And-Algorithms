//Done
//27.7.1
//For optimised calculation of diameter code refer this: heightAndDiaBTAnother.cpp
////Time complexity to calculate Height of the tree: O(n)
//Diameter : Number of nodes in the longest path between any 2 levels
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

int calcHeight(Node* root){ // to get height
    if(root == NULL){
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    return max(lHeight, rHeight) + 1;
}

int calcHeightD(Node* root){ // to get diameter
    if(root == NULL){
        return 0;
    }
    return max(calcHeightD(root->left), calcHeightD(root->right)) + 1;
}

int calcDiameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int lHeight = calcHeightD(root->left);
    int rHeight = calcHeightD(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left); // Calculating diameter for each node so that there may be a case where a root may or may not be included in the diameter length
    int rDiameter = calcDiameter(root->right);
    return max(currDiameter, max(lDiameter, rDiameter));
}

// int calcDiaOptimized(Node* root, int* height){
//     if(root == NULL){
//         *height = 0; 
//         return 0;
//     }
//     int lh = 0, rh = 0;
//     int lDia = calcDiaOptimized(root->left, &lh);
//     int rDia = calcDiaOptimized(root->right, &rh);

//     int currDiameter = lh + rh + 1;
//     *height = max(lh, rh) + 1;
//     return max(currDiameter, max(lDia, rDia));
// }

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //         1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7

    // root->right->right->right = new Node(7); // This line creates a duplicate node

    cout << calcHeight(root) << " "; // Time complexity: O(n)
    cout << calcDiameter(root) << " "; // Time complexity: O(n^2)

    // Calculate diameter optimized
    int height = 0;
   // cout << calcDiaOptimized(root, &height) << " "; // Time complexity: O(n)
    return 0;
}
