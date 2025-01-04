//DOne
//Time complexity of both the fuctions is O(n)
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

void printLevelOrder(Node * root){
    if(root== NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node = q.front();//since we are pushing NULL in else if condition, we need to check if the front element is NULL or not, if it is NULL then we need to push NULL again to mark the end of the level 
        q.pop();
        if(node != NULL){
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}
//For the given tree, the correct queue sequence is: 1, NULL, 2, 3, NULL, 4, 5, 6, 7, NULL.


int sumAtKLevel(Node* root, int k){
    if(root== NULL){
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level=0; 
    int sum=0;
    while(!q.empty()){
        Node* node= q.front();
        q.pop();
        if(node != NULL){
            if(level == k){
                sum+= node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;//The key difference is incrementing the level when we encounter a NULL in the queue. This way, we can keep track of the current level and sum the nodes at that level.
        }
        
    }
    return sum;
}

int main(){
    struct Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);


    /*
               1
             /  \
            2    3
           / \  / \
          4   5 6  7
     */
    ////level order traversal
    printLevelOrder(root);
    cout<<endl;
    cout<<sumAtKLevel(root, 2);// Computes the sum of nodes at the Kth level. Similar to level order traversal, but instead of printing nodes, it sums them at each level and returns the total sum at the specified level.

    ////finding sum at kth level  
    return 0;
}

////Output
// 1 2 3 4 5 6 7 
// 22