#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
    node(int val) { // Constructor to initialize the node
        data = val;
        next = NULL;
    }
};

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(node*& head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

int length(node*& head) {
    int l = 0;
    node* temp = head;
    while (temp != NULL) {
        l++;
        temp = temp->next;
    }
    return l;
}

node* kAppend(node*& head, int k) {
    node* newHead;
    node* newTail;
    node* tail = head;
    int l = length(head);
    k = k % l; // Ensure k is within the bounds of the list length
    int count = 1;
    while (tail->next != NULL) {
        if (count == l - k) {
            newTail = tail;
        }
        if (count == l - k + 1) {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

int main() {
    node* head = NULL; // Linked list does not have a specific name like a variable would
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        insertAtTail(head, arr[i]);
    }
    display(head);
    node* newHead = kAppend(head, 3);
    display(newHead);
    head = newHead; // Update head to newHead

    return 0;
}
