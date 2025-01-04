////Learn this code obtained from comment
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTreeNode{
  public:
  T data;
  BinaryTreeNode<T>* left;
  BinaryTreeNode<T>* right;
  
  BinaryTreeNode(T data){
      this->data = data;
      left = NULL;
      right = NULL;
  }
  
  ~BinaryTreeNode(){
      delete left;
      delete right;
  }
};
void printLevelWise(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    
    cout<<root->data<<":";
    if(root->left != NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printLevelWise(root->left);
    printLevelWise(root->right);
}
BinaryTreeNode<int>* TakeInputwise(){
    int rootData;
    cout<<"enter root data -> ";
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size() != 0){
        BinaryTreeNode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        int leftchildata;
        cout<<"enter left data of"<<front->data;
        cin>>leftchildata;
        if(leftchildata != -1){
            BinaryTreeNode<int>* leftchild = new BinaryTreeNode<int>(leftchildata);
            front->left = leftchild;
            pendingnodes.push(leftchild);
        }
        int rightchildata;
        cout<<"enter right data of"<<front->data;
        cin>>rightchildata;
        if(rightchildata != -1){
            BinaryTreeNode<int>* rightchild = new BinaryTreeNode<int>(rightchildata);
            front->right = rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;
}

int main(){
    BinaryTreeNode<int>* root = TakeInputwise();
    printLevelWise(root);
    delete(root);
    return 0;
}