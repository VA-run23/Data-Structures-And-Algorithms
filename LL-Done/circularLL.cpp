//Done
#include <bits/stdc++.h>
using namespace std;

// class node {
// public:
//     int data;
//     node *next;
//     node(int val) {
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
void insertAtHead(node* &head, int val) {
    // Create a new node with the given value
    node* n = new node(val);

    // If the list is empty (head is NULL)
    if (head == NULL) {
        n->next = n; // Point the new node to itself (circular reference)
        head = n;    // Make the new node the head of the list
        return;      // Exit the function
    }

    // Initialize a temporary pointer to traverse the list
    node *temp = head;

    // Traverse the list to find the last node
    while (temp->next != head) {
        //Assume we have a circular linked list: 3 -> 5 -> 7 -> 9 -> 3 (where 3 is the head).
        // since even the last node it pointing to the head , the condition in while loop is temp->next != head
        // Since this is a circular linked list, the last node’s next pointer will point to the head
        temp = temp->next;
    }

    // Update the next pointers to insert the new node at the head
    temp->next = n; // Last node points to the new node
    n->next = head; // New node points to the old head
    head = n;       // Update the head to the new node
    //  3 -> 5 -> 7 -> 9 -> 3
    // 1 / 3 / 5 / 7 / 9 / 1 (circular link)


}


void insertAtTail(node* &head, int val) {
    if (head == NULL) {
        insertAtHead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void deleteAtHead(node* &head) {
    // Initialize temp to head
    node* temp = head;//head is a pointer to the first node in the linked list. When you start traversing, head holds the address of the first node
    // node* toDelete = head;this line can be placed here also

    // Traverse to the last node (the node whose next points to head)
    while (temp->next != head) {
        temp = temp->next;
    }

    // Save the current head node in a toDelete pointer
    node* toDelete = head;

    // Link the last node (temp) to the second node (head->next)
    temp->next = head->next;

    // Update head to the second node (head->next)
    head = head->next;

    // Delete the old head node
    delete toDelete;
}


void deletion(node*  &head, int pos){

    if(pos==1){
        deleteAtHead(head);
        return;
    }

    node* temp= head;
    int count =1;
    while(count !=pos-1){
        temp=temp->next;
        count++;
    }
    node*toDelete=temp->next;//the temp->next node is to be deleted
    temp->next=temp->next->next;//temp->next is bypassed

    delete toDelete;
}

void display(node* head) {
    if (head == NULL) return;
    node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    display(head);
    insertAtHead(head, 6);
    display(head);
    deletion(head, 5);//here second argument is position
    cout<<"deletion at specified place: ";
    display(head);
    deleteAtHead(head);
    cout<<"deletion at head: ";
    display(head);
    return 0;
}