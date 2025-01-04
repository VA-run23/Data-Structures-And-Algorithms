//Done
//dubly linked list has three values rather than two, that is
//node[previous, data, next]

#include <bits/stdc++.h>
using namespace std;

// class node{
// public:
//     int data;
//     node *next;
//     node* prev;
//     node(int val){
//         data = val;
//         next = NULL;
//         prev = NULL;
//     }
// };

struct node {
    int data;       // Data stored in the node
    node* next;     // Pointer to the next node
    node* prev;     // Pointer to the previous node

    node(int val) {//direct use of struct pointer without using "struct node*" in cpp
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// is this correct or this?
//The answer to this is that , it is right in C language not in cpp

// struct node {
//     int data;       // Data stored in the node
//     node* next;     // Pointer to the next node
//     node* prev;     // Pointer to the previous node

////You cannot have constructors for structure in C language like below
    // // // node(int val) {// but in c for pointer you have to specify it as "struct node*"
    // // //     data = val;
    // // //     struct node* next = NULL;
    // // //     struct node* prev = NULL;
    // // // }
// };


void insertAtHead(node* &head, int val){
    node* n= new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    //n ka previous hai wo already NULL ko hi point kar raha hoga due to constructor
    head=n;//ab n list ka head hogaya
}

void display(node *head){
    node *temp = head;
    while (temp != NULL){
        cout << temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertAtTail(node *&head, int val){

    if(head==NULL){
        insertAtHead(head, val);
        return;
    }

    node *n = new node(val);
    node* temp=head;

    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev=temp;
    //and by default n->next is NULL
}


void deleteAtHead(node* &head){
    node* toDelete=head;
    head=head->next;
    //here head is pointing to first node of the ll and head->next is second node of the linked list
    head->prev=NULL;
    delete toDelete;
}

void deletion(node* &head, int pos) {
    // If position to delete is the head (first node)
    if (pos == 1) {
        deleteAtHead(head); // Use a separate function to handle deletion of head
        return; // Exit the function
    }

    node* temp = head; // Initialize temp to head for traversal
    int count = 1; // Initialize a counter to track the current position

    // Traverse the list to find the node at the given position
    while (temp != NULL && count != pos) {
        temp = temp->next; // Move to the next node
        count++; // Increment the position counter
    }
    // Adjust the pointers of the surrounding nodes to skip the current node
    temp->prev->next = temp->next; // Link the previous node to the next node

    // If the node to be deleted is not the last node, we have to make sure that the temp->next node's previous is pointing to the temp's previous node if (temp->next != NULL) { temp->next->prev = temp->prev; // Link the next node to the previous node
    delete temp; // Delete the current node
}

int main(){
    node* head=NULL;
  insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    display(head);
    insertAtHead(head, 8);
    display(head);
    deletion(head, 3);
    display(head);
    deletion(head, 1);
    display(head);
    return 0;
}