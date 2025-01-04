//Done
// the function searchInBST doesn't work if the values are not ordered in BST
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


// The inorder successor of a node in a Binary Search Tree (BST) is the node with the smallest value that is greater than the current node's value. This is why we often look at the right subtree of the current node to find the inorder successor. If the current node has a right child, the inorder successor is the leftmost node in the right subtree. If the current node does not have a right child, we look at its ancestors to find the smallest value greater than the current node's value.
Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left; // returning the left most value of the right subtree of the current node
    }
    return curr; // If that node has no left child it returns the current node itself
}

Node *deleteInBST(Node *root, int key)
{ // Function to delete a node with the given key in the BST

    if (key < root->data)
    {
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }
    else
    { // If the node to be deleted is found
        if (root->left == NULL)
        {                             // If the node to be deleted has only a right child
            Node *temp = root->right; // store the right child into temp and return it after deleting the current node, so that it levels up(moves up)
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {                            // If the node to be deleted has only a left child
            Node *temp = root->left; // store the left child into temp and return it after deleting the current node, so that it levels up(moves up)
            free(root);
            return temp;
        }

        // If the node has both left and right children, find the inorder successor (smallest value in the right subtree)
        // The inorder successor of a node in a Binary Search Tree(BST) is the node with the smallest value
        // that is greater than the current node 's value. This is why we often look at the right subtree of
        // the current node to find the inorder successor. If the current node has a right child, the inorder successor is the leftmost node in the right subtree.
        // If the current node does not have a right child, we look at its ancestors to find the smallest value greater than the current node' s value.
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    struct Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->left->right->right = new Node(17);

    //BST for deleting value 2
    cout<<"BST before deleting"<<endl;
    inorder(root);
    root= deleteInBST(root, 15);
    cout<<endl;
    cout<<"BST after deleting"<<endl;
    inorder(root);
    return 0;
}


// //Output
// BST before deleting 17
// 5 10 15 17 20 30 
//         20
//        /  \
//      10    30
//     /  \
//    5   15
//         \
//         17

// BST after deleting
// 5 10 15 20 30 
//         20
//        /  \
//      10    30
//     /  \
//    5   15


//Output 2
// BST before deleting 15
// 5 10 15 17 20 30 
//         20
//        /  \
//      10    30
//     /  \
//    5   15
//         \
//         17

// BST after deleting 15
// 5 10 17 20 30 
//         20
//        /  \
//      10    30
//     /  \
//    5   17
