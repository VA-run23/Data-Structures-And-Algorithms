//
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

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointers(Node* root, Node** first, Node** mid, Node** last, Node** prev) {
    if (root == NULL) {
        return;
    }

    // Recur for the left subtree
    calcPointers(root->left, first, mid, last, prev);

    // If this node is smaller than the previous node, it's violating the BST rule
    if (*prev && root->data < (*prev)->data) {
        // If this is the first violation, mark these two nodes as 'first' and 'mid'
        if (!*first) {
            *first = *prev;
            *mid = root;
        } else {
            // If this is the second violation, mark this node as 'last'
            *last = root;
        }
    }

    // Mark this node as the previous node for the next iteration of the inorder traversal
    *prev = root;

    // Recur for the right subtree
    calcPointers(root->right, first, mid, last, prev);
}

void restoreBST(Node* root) {
    Node* first = NULL, *mid = NULL, *last = NULL, *prev = NULL;
    calcPointers(root, &first, &mid, &last, &prev);

    // Fix the BST by swapping the necessary nodes
    if (first && last) {
        swap(&(first->data), &(last->data));
    } else if (first && mid) {
        swap(&(first->data), &(mid->data));
    }
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    struct Node* root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);

    cout << "Inorder traversal of the original tree: ";
    inorder(root);
    cout << endl;

    restoreBST(root);

    cout << "Inorder traversal of the fixed tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
