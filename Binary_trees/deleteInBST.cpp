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

// search in BST
Node *searchInBST(Node *root, int key)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        return searchInBST(root->left, key);
    }
    return searchInBST(root->right, key);
}

// The inorder successor of a node in a Binary Search Tree (BST) is the node with the smallest value that is greater than the current node's value. 
//This is why we often look at the right subtree of the current node to find the inorder successor.
// If the current node has a right child, the inorder successor is the leftmost node in the right subtree.
// If the current node does not have a right child, we look at its ancestors to find the smallest value greater than the current node's value.
Node *inorderSucc(Node *root){//as we have passed inorderSucc(root->right) in the deleteInBST function, so it will always return the leftmost value of the right subtree of the current node
    Node *curr = root;//since we are passing the right child of the current node, we are storing the right child in curr

    while (curr && curr->left != NULL)//curr && is because it checks if the current node is not null(that is initial root->right)
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
        // The inorder successor of a node in a Binary Search Tree(BST) is the node with the smallest value that is greater than the current node 's value. 
        //This is why we often look at the right subtree of the current node to find the inorder successor. 
        //If the current node has a right child, the inorder successor is the leftmost node in the right subtree.
        // If the current node does not have a right child, we look at its ancestors to find the smallest value greater than the current node' s value.
        Node *temp = inorderSucc(root->right); // Find the in-order successor of the current node, which is the smallest node in the right subtree
        root->data = temp->data; // Replace the data of the current node with the in-order successor's data
        root->right = deleteInBST(root->right, temp->data); // Delete the in-order successor node from the right subtree
        
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
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    struct Node *root1 = new Node(16);
    root1->left = new Node(10);
    root1->left->right = new Node(14);

    bool temp = false;
    if(deleteInBST(root1, 16)) cout<<"VALUE DELETED"<<endl;

    if (searchInBST(root, 5) == NULL)
    {
        cout << "Key does not exist" << endl;
    }
    else
    {
        cout << "Key exists" << endl;
    }

    // cout<<"BST before deleting"<<endl;
    // inorder(root);
    // root= deleteInBST(root, 5);
    // cout<<endl;
    // cout<<"BST after deleting"<<endl;
    // inorder(root);
    // cout<<endl;

    ////BST for deleting value 2
    // cout<<"BST before deleting"<<endl;
    // inorder(root);
    // root= deleteInBST(root, 2);
    // cout<<endl;
    // cout<<"BST after deleting"<<endl;
    // inorder(root);
    // return 0;
}

////output for deleting 5
// Key exists
// BST before deleting
// 1 2 3 4 5 6 7
// BST after deleting
// 1 2 3 4 6 7

/////Output for deleting value 2
// BST before deleting
// 1 2 3 4 6 7
// BST after deleting
// 1 3 4 6 7

//////////////////////////
/*
Summary:
1. Find the in-order successor (smallest value in the right subtree).
2. Replace the data of the current node with the data of the in-order successor.
3. Delete the in-order successor from the right subtree.

This method maintains the properties of the BST and ensures that the tree remains balanced after deleting a node with two children. Here is a simple illustration of the steps:

Original Tree:
    10
   /  \
  5   15
      / \
     12  20

After finding in-order successor (12):
    10
   /  \
  5   15
      / \
     12  20

Replacing data:
    12
   /  \
  5   15
      / \
     X   20  (X denotes the original position of 12)

Deleting in-order successor:
    12
   /  \
  5   15
        \
         20
*/


// 16
// /
// 10
//  \ 
//  14