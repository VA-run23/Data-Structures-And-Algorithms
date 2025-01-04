//Done
//TC: O(n)
//22.3
#include <bits/stdc++.h>
using namespace std;
////time complexity: O(n)

class node{//node is an object consisting of attributes data and pointer next and a constructor function
    public:
    int data; 
    node* next;//A pointer to the next node in the list.
    node(int val){// Constructor that initializes the node with a value and sets the next pointer to NULL.
        data=val;
        next=NULL;
    }
};
void display(node* head){
    node* temp=head; //we could have used head also instead of temp
    //no the head should always point to the first node of the LL
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp=temp->next;//Moves to the next node.
    }
    cout<<"NULL"<<endl;
} 

node* reverse(node* &head) {
    node* prePtr = NULL; // Previous pointer, initially NULL
    node* currPtr = head; // Current pointer, initially pointing to the head
    node* nextPtr; // Next pointer for traversal

    while (currPtr != NULL) { // Loop until the end of the list is reached
        nextPtr = currPtr->next; // Store the next node (moving forward)
        currPtr->next = prePtr; // Reverse the current node's pointer (pointing backwards)

        prePtr = currPtr; // Move the previous pointer to the current node (moving forward)
        currPtr = nextPtr; // Move the current pointer to the next node (moving forward)
    }
    return prePtr; // Return the new head of the reversed list
}

void insertAtTail(node* &head , int val){
    node*n =new node(val);
    if(head==NULL){
        head = n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next; 
    }
    temp->next=n;
}


node* reverseRecursive(node* &head){

    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newHead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
   ///// head->=NULL;//can we write like this?  No we can't write like this
   return newHead;

}
int main(){
    node* head=NULL;
    int n;
    cin>>n;
   
    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        insertAtTail(head, x);
    }
    // insertAtTail(head, 1);
    // insertAtTail(head, 2);
    // insertAtTail(head, 3);
    display(head);
    // node* newHead=reverse(head);
    node* newHead=reverseRecursive(head);

    display(newHead);
    return 0;
}