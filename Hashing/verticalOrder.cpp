//32.4
// time complexity: O(nLog(n))
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) builtin_popcount(x)

struct Node{
    int key;
    Node *left, *right;
};
Node* newNode(int key){//function
    Node* node = new Node;
    node->key = key;
    node->left = node ->right = NULL;
}

void getVerticalOrder(Node*root, int hdis, map<int, vi> &m){//here passing by reference , because if passed by value, we would get multiple maps storing the distance , but not in a single map 
    if(root == NULL){
        return ;
    }
    m[hdis].push_back(root->key);//since we are passing the horizontal distance with function call is just make suitable changes and adds to the map
    getVerticalOrder(root->left, hdis-1, m);
    getVerticalOrder(root->right, hdis+1, m);

}

int main(){
    Node *root = newNode(10);
    root->left = newNode(7);
    root->right  = newNode(4);
    root->left->left = newNode(3);
    root->left->right  = newNode(11);
    root->left->right->right  = newNode(1000);

    root->right->left = newNode(14);
    root->right->right = newNode(6);

    map<int, vector<int>> m;//this map has the final answer
    //map<int, vi> &m: A map where keys are horizontal distances and values are vectors of node keys at that distance.
    int hdis = 0;
    getVerticalOrder(root, hdis, m);
    map<int, vi> :: iterator it;
    for(it = m.begin(); it != m.end(); it++){
        for(int i = 0; i<(it->ss).size(); i++){
            cout<<(it->ss)[i]<<" "<<endl;
        }
        cout<<endl;
    }
    return 0;
}

    //     10
    //    /  \
    //   7    4
    //  / \   / \
    // 3  11 14  6
    //      \
    //      1000
// Horizontal Distance -2: 3
// Horizontal Distance -1: 7
// Horizontal Distance 0: 10, 11, 14
// Horizontal Distance 1: 4, 1000
// Horizontal Distance 2: 6

// The left child of a node decreases the horizontal distance by 1.
// The right child of a node increases the horizontal distance by 1.


// // When you pass the map by reference, the function getVerticalOrder works with the original map m. 
// This ensures that all updates to the map are made in a single, shared map, which is crucial for correctly storing the vertical order of nodes.

// // If you were to pass the map by value, each call to the function would work with a copy of the map.
//  This would result in multiple maps, each containing only a part of the data, rather than a single map that accumulates all the vertical distances and corresponding nodes.


// //Output
// 3 

// 7 

// 10 
// 11 
// 14 

// 1000 
// 4 

// 6 
