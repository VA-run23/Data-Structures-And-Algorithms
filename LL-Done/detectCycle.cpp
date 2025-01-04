//Done
#include <bits/stdc++.h>
using namespace std;

// class node{
// public:
//     int data;
//     node *next;
//     node(int val){
//         data = val;
//         next = NULL;
//     }
// };

struct node {
    int data;
    node* next;
    node(int val) { // Constructor to initialize the node
        data = val;
        next = NULL;
    }
};

void display(node *head){
    node *temp = head;
    while (temp != NULL){
        cout << temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void insertAtTail(node *&head, int val){
    node *n = new node(val);
    if (head == NULL){
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

bool detectCycle(node* &head){
    node* slow =head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){//This runs till fast encounters NULL and NULL doesnot exist if it is circular
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}

void makeCycle(node* head, int pos) {
    node* temp = head;    // Initialize temp to point to the head
    node* startNode;      // This will eventually point to the start node of the cycle
    int count = 1;        // Counter to keep track of the current node position
    
    // Traverse the list to find the last node and the start node of the cycle
    while (temp->next != NULL) {
        if (count == pos) {
            startNode = temp; // When count matches pos, set startNode to temp
        }
        temp = temp->next;    // Move to the next node
        count++;              // Increment the position counter
    }
    
    // temp now points to the last node of the list
    temp->next = startNode;   // Create the cycle by pointing the last node's next to the startNode
    // The last node's next pointer will point to the node at position pos, creating a cycle
}

    void removeCycle(node* &head) {
        node* slow = head;
        node* fast = head;

        // Detect cycle using slow and fast pointers
        do {
            slow = slow->next;         // Slow moves one step
            fast = fast->next->next;   // Fast moves two steps
        } while (slow != fast);         // Loop until slow and fast meet (same address)
        //The slow and fast pointers do not necessarily meet at the first node (head node) or the starting node of the cycle. They meet somewhere within the cycle itself, which could be any node in the cycle.

        // Reset fast to head
        fast = head;

        // Find the start of the cycle
        while (slow->next != fast->next) {
            slow = slow->next;         // Move slow one step
            fast = fast->next;         // Move fast one step
        }

        // Break the cycle
        slow->next = NULL;             // Set the next of the meeting point to NULL
    }



int main(){
    node* head=NULL;//here head is just a pointer to the first node of the linked list

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    makeCycle(head, 3);
    // display(head);
    cout<<"Cycle detection "<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<"Cycle detection "<<detectCycle(head)<<endl;
    display(head);
    return 0;
}