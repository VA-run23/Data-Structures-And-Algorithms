//Done
//TC: O(n)
//22.11

////Putting elements in odd places first then putting elements of even places after the odd ones
#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void display(node *head){
    node *temp = head;
    while (temp != NULL){
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
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

void evenAfterOdd(node* & head) { // Reorder the list so that nodes at odd positions come before nodes at even positions
    node* odd = head; // Initialize odd pointer at the head
    node* even = head->next; // Initialize even pointer at the second node
    node* evenStart = even; // Keep track of the start of even nodes

    while (odd->next != NULL && even->next != NULL) {
        odd->next = even->next; // Link the current odd node to the next odd node
        odd = odd->next; // Move odd pointer to the next odd node
        even->next = odd->next; // Link the current even node to the next even node
        even = even->next; // Move even pointer to the next even node
    }

    odd->next = evenStart; // Link the last odd node to the first even node

    // Ensure the last even node points to NULL
    if (odd->next != NULL) {
        even->next = NULL;
    }
}


int main() {
    node* head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        insertAtTail(head, arr[i]);
    }
    display(head);
    evenAfterOdd(head);
    display(head);
    return 0;
}
// //Output
// 1 2 3 4 5 6 
// 1 3 5 2 4 6 