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
void display(node *head){//receiving node pointer or value at node pointer?
    node *temp = head;
    while (temp != NULL){//While node pointer is not pointing to NULL
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void insertAtTail(node *&head, int val){//*&head : Pass by reference
    node *n = new node(val);//randomly creating a node 
    if (head == NULL){
        head = n;
        return;
    }
    //Preserve head: You don’t want to move the head pointer around because it’s your link to the start of the list. Using temp ensures head remains unchanged.
    //Traversal: temp acts as a movable pointer to walk through the nodes without losing the start point. Think of it as a traveler who explores while the head stays home.
    //Thus, temp lets you wander through the list while keeping head intact.
    node *temp = head;//The temporary pointer temp is initialized to point to the head of the list so that you can traverse the list without losing track of where it starts.
    //head should always point to first node
    while (temp->next != NULL){//By using temp, you preserve the head pointer, which always points to the beginning of the list.
        temp = temp->next;
    }
    //By setting temp = head and using the loop while (temp->next != NULL), you're traversing the list until you reach the last node (the tail). 
    //Once there, you can attach your new node by setting temp->next = n. 
    //This ensures the new element is inserted precisely at the tail, preserving the structure and order of your linked list.
    temp->next = n;
}

int length(node* &head){
    int l=0;
    node* temp=head;//pointing temp to the address of the head
    while(temp!= NULL){
        l++; 
        temp=temp->next;
    }
    return l;
}

////appending last k nodes to the first
node* kAppend(node* &head, int k) {
    int l = length(head); // Calculate the length of the list
    k = k % l; // Adjust k to be within the list length

    node* newHead; // New head will be at (l-k+1)th node
    node* newTail; // New tail will be at (l-k)th node
    node* tail = head; // Initialize tail to head for traversal
    //tail is used just for traversal

    int count = 1;
    while (tail->next != NULL) {
        if (count == l - k) { // This node will be the new tail after changes
            newTail = tail;
        }
        if (count == l - k + 1) { // This node will be the new head after changes
            newHead = tail;
        }
        tail = tail->next; // Move to the next node
        count++;
    }
    newTail->next = NULL; // After all, point the newTail to NULL
    tail->next = head; // Link the last node (tail of the original linked list) to the old head, which was previously pointing to NULL
    return newHead; // Returning the new head of the list(which is l-k+1 th element)
}

int main() {
    node* head = NULL;//Linked list doesnot have specific name like variable would
    //The head is simply a pointer that marks the start of your linked list. It doesn't hold any data by itself; its job is to point to the first node, which contains the actual data.
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        insertAtTail(head, arr[i]);
    }
    display(head);//passing a node pointer
    node* newHead = kAppend(head, 3);
    display(newHead);
    head = newHead; // Update head to newHead////
    newHead = kAppend(head, 3);
    display(newHead);
    return 0;
}
////other way : 
// void kAppend(node* &head, int k) {
//     if (head == NULL || k == 0) {
//         return;
//     }

//     node* newHead;
//     node* newTail;
//     node* tail = head;
//     int l = length(head);
//     k = k % l;
//     if (k == 0) {
//         return;
//     }
//     int count = 1;
//     while (tail->next != NULL) {
//         if (count == l - k) {
//             newTail = tail;
//         }
//         if (count == l - k + 1) {
//             newHead = tail;
//         }
//         tail = tail->next;
//         count++;
//     }
//     newTail->next = NULL;
//     tail->next = head;
//     head = newHead; // Update head directly within the function
// }