#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* searchInBST(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == key) {
        return root;
    }
    if (root->data > key) {
        return searchInBST(root->left, key);
    }
    return searchInBST(root->right, key);
}

int main() {
    struct Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    /*
               4
             /   \
            2     6
           / \   / \
          1   3 5   7
     */

    if (searchInBST(root, 5) == NULL) {
        cout << "Key does not exist" << endl;
    } else {
        cout << "Key exists" << endl;
    }
    return 0;
}
