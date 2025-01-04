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

void rightView(Node* root) {
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
            if (i == n - 1) {//the only difference between right side view and left side view
                //When i equals n - 1, it means that the current node is the last node at this level. This is important for the right side view because the last node at each level is the rightmost node visible from the right side of the tree.
                cout << curr->data << " "; //; // Print the last node of each level (rightmost node)
                // Print the last node of each level
                //SInce most of the times,  the right node's value is the last pushed value, print its data
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
    // Right view
    rightView(root);
    cout<<endl;


      struct Node* root2 = new Node(1);
    root2->left = new Node(2);
    // root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

      /*
               1
             /  
            2   
           / \  
          4   5 
     */
    // Right view
    rightView(root2);

    return 0;
}


/*
Initially, the root is added to the queue.
While the queue is not empty, a copy of the front element is put into `current`, and the queue element is popped.
Using a for loop, only the rightmost element of each level is printed, and the other elements of the same level are popped.
The children of the current node are added to the queue, with the left child added first, followed by the right child.
This process continues until the queue is empty, ensuring the right view of the tree is printed.
*/
