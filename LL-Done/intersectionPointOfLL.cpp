//Done
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
int length(node* &head){
    int l=0;
    node* temp=head;
    while(temp!= NULL){
        l++; 
        temp=temp->next;
    }
    return l;
}

void intersect(node* head1, node* head2, int pos){
    node* temp1 = head1;
    pos--;//First Decrement: Adjusts the position from 1-based to 0-based.
    // This decrement is outside the loop, ensuring pos is reduced by 1 before the loop starts.
    // It adjusts pos because positions in linked lists typically start at 1, not 0. If you want to intersect at the 5th position, you actually need to move 4 steps from the head (0-based index).
    // Traverse to the position where intersection needs to occur
    while(pos--) {
        temp1 = temp1->next;
    }
    node* temp2 = head2;
    // Traverse to the end of the second list
    while(temp2->next != NULL) {
        temp2 = temp2->next;
    }
    // Create the intersection
    temp2->next = temp1;
}

int intersection(node* head1, node* head2){
    int l1=length(head1);
    int l2=length(head2);
    int d=0;
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }else{
        d=l2-l1;//so that ptr1 points to longer LL
        ptr1=head2;
        ptr2=head1;
    }
    while(d){
        ptr1=ptr1->next;
        if(ptr1== NULL){
            return -1;
        }
        d--;
    }
    while(ptr1 != NULL && ptr2 !=NULL){
        if(ptr1== ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

int main(){
       node * head1=NULL;
       node * head2=NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 7);
    insertAtTail(head1, 6);
    insertAtTail(head2, 7);
    insertAtTail(head2, 7);
    insertAtTail(head2, 7);

    intersect(head1, head2, 5);//intersection at 5th position

    display(head1);
    display(head2);
    cout<<intersection(head1, head2)<<endl;
    return 0;
}
