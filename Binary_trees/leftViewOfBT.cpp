//Done
// Time complexity: O(n)
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

void leftView(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();
            if (i == 0) {
                cout << curr->data << " "; // Print the first node of each level
            }
            if (curr->left != NULL) {
                q.push(curr->left); // Traverse left first
            }
            if (curr->right != NULL) {
                q.push(curr->right); // Then traverse right
            }
        }
    }
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    /*
               1
             /  \
            2    3
           / \  / \
          4   5 6  7
     */
    // Left view
    leftView(root);


    struct Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);
    root1->left->right->left = new Node(8);

        //        1
        //      /  \
        //     2    3
        //    / \  / \
        //   4   5 6  7
        //      /
        //     8
        cout<<endl;
    leftView(root1);
    return 0;
}
/*
Initially, the root is added to the queue.
While the queue is not empty, a copy of the front element is put into `current`, and the queue element is popped.
Using a for loop, only the leftmost element of each level is printed, and the other elements of the same level are popped.
The children of the current node are added to the queue, with the left child added first, followed by the right child.
This process continues until the queue is empty, ensuring the left view of the tree is printed.
*/
