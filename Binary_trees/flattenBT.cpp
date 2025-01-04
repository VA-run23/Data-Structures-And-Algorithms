//Detailed explaination of the code is given below
//Done
//TC: 
//
//Flattening the tree means to move the left child to the parent's right child position, and then attach the original right child to the end of the new right subtree.
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
void flatten(Node* root) {
    if (root == NULL) {//when root  == NULL it returns and the recursive call to the parent(of leaf node) is processing
        return;
    }

    if (root->left != NULL) {
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while (t->right != NULL) {
            t = t->right;
        }
        t->right = temp;
    }

    flatten(root->right);
}

void inorderPrint(Node* root){
    if(root == NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);


}


int main() {
    // Case 1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);
    flatten(root1);
    inorderPrint(root1);
    cout << endl;

    // Case 2
    Node* root2 = new Node(4);
    root2->left = new Node(9);
    root2->right = new Node(5);
    root2->left->left = new Node(1);
    root2->left->right = new Node(3);
    root2->right->right = new Node(6);
    flatten(root2);
    inorderPrint(root2);
    cout << endl;

    // Case 3
    Node* root3 = new Node(15);
    root3->left = new Node(10);
    root3->right = new Node(20);
    root3->left->left = new Node(8);
    root3->left->right = new Node(12);
    root3->right->left = new Node(17);
    root3->right->right = new Node(25);
    root3->left->left->left = new Node(6);
    root3->left->left->right = new Node(9);
    root3->right->left->left = new Node(16);
    root3->right->left->right = new Node(18);
    flatten(root3);
    inorderPrint(root3);
    cout << endl;

    return 0;
}

///case 1
// /*
//            1
//          /  \
//         2    3
//        / \  / \
//       4   5 6  7
// */
// 1
//  \
//   2
//    \
//     4
//      \
//       5
//        \
//         3
//          \
//           6
//            \
//             7



//Case 2
//     /*
//               4
//              / \
//             9   5
//            / \   \
//           1   3   6
//     */
// //    4 9 1 3 5 6 
// 4
//  \
//   9
//    \
//     1
//      \
//       3
//        \
//         5
//          \
//           6




////Case 3

//         15
//        /  \
//      10    20
//     / \    / \
//    8  12  17  25
//   / \     / \
//  6   9   16  18

//15 10 8 6 9 12 20 17 16 18 25 
// 15
//  \
//   10
//    \
//     8
//      \
//       6
//        \
//         9
//          \
//           12
//            \
//             20
//              \
//               17
//                \
//                 16
//                  \
//                   18
//                    \
//                     25


// Step-by-Step Flattening:
// Flatten Subtree rooted at 8:

//     15
//    /  \
//   10   20
//  / \   / \
// 8   12 17 25
//  \
//   6
//    \
//     9
// Attach flattened subtree of 8 to node 10:

//     15
//    /  \
//   10   20
//    \   / \
//     8  17 25
//      \
//       6
//        \
//         9
//        / \
//       12
// Flatten Subtree rooted at 10:

//     15
//    /  \
//   10   20
//    \   / \
//     8  17 25
//      \
//       6
//        \
//         9
//          \
//          12
// Attach flattened subtree of 10 to node 15:

//     15
//      \
//     10
//      \
//       8
//        \
//         6
//          \
//           9
//            \
//            12
//            / \
//           20
// Flatten Subtree rooted at 17:

//     15
//      \
//     10
//      \
//       8
//        \
//         6
//          \
//           9
//            \
//            12
//             \
//             20
//             /
//           17
//            \
//            16
//            / \
//           18
// Attach flattened subtree of 20 to node 15:

//     15
//      \
//     10
//      \
//       8
//        \
//         6
//          \
//           9
//            \
//            12
//             \
//             20
//              \
//              17
//               \
//               16
//                \
//                18
//                / \
//               25
// Finally, the flattened tree will be:

// 15
//  \
//  10
//   \
//    8
//     \
//      6
//       \
//        9
//         \
//         12
//          \
//          20
//           \
//           17
//            \
//            16
//             \
//             18
//              \
//              25