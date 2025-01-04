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
        cout << temp->data<<endl;
        cout<<temp<<endl;
        temp = temp->next;
    }
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
    return 0;
}


////Output
// 1
// 0x891850
// 2
// 0x891860
// 3
// 0x891890
// 4
// 0x8918a0
// 5
// 0x8918b0
// 6
// 0x8918c0
// 7

////Note
// The addresses you see are determined by the memory allocator and how it assigns memory for new objects. The gaps in the addresses (like the missing `0x891870` and `0x891880`) can occur due to several reasons:
// 1. **Memory Alignment**: The memory allocator often aligns memory addresses to certain boundaries (e.g., 8-byte or 16-byte boundaries) for performance reasons. This can cause gaps in the addresses.
// 2. **Fragmentation**: The memory allocator might have allocated memory for other objects or internal structures in those gaps, leading to non-contiguous addresses for your nodes.
// 3. **Heap Management**: The way the heap is managed by the operating system and the runtime environment can also lead to non-contiguous memory allocation.
//These gaps are normal and expected behavior in dynamic memory allocation.