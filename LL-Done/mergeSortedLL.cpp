//Done
//22.9: Merging two sorted Linked List 
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

//TC:O(n+m)
    node* merge(node* &head1, node* &head2) {
        node* p1 = head1;
        node* p2 = head2;
        node* dummyNode = new node(-1); // dummyNode is a pointer to a node

    // dummyNode is a node with its data set to -1.
    // dummyNode->next will eventually point to the head of the merged list.

        node* p3 = dummyNode; // The sorted linked list is being built using p3

        // Merge the two lists until one list is exhausted
        while (p1 != NULL && p2 != NULL) {
            if (p1->data < p2->data) {
                p3->next = p1;
                p1 = p1->next;
            } else {
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }

        // Add remaining nodes of p1, if any
        while (p1 != NULL) { // Adding remaining nodes of p1 when p2 has reached its end
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }

        // Add remaining nodes of p2, if any
        while (p2 != NULL) { // Adding remaining nodes of p2 when p1 has reached its end
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }

        // Return the head of the merged list, which starts at dummyNode->next
        return dummyNode->next; // Returning dummyNode->next as the sorted linked list starts from there (dummyNode is initialized with -1)
    }

    node* mergeRecursive(node* &head1, node* head2){

        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
        node* result;
        if(head1->data < head2->data){
            result=head1;
            result->next=mergeRecursive(head1->next, head2); 
        }else{
            result =head2;
            result->next = mergeRecursive(head1, head2->next);
        }
        return result;
    }

int main(){
    node* head1=NULL;
    node* head2=NULL;
    int arr1[]={1,4,5, 7};
    int arr2[]={2,3,6};
    for(int i=0; i<4; i++){
        insertAtTail(head1, arr1[i]);
    }
    for(int i=0; i<3; i++){
        insertAtTail(head2, arr2[i]);
    }
    display(head1);
    display(head2);
    // node* newHead=merge(head1, head2);
    // display(newHead);
     node* newHead=mergeRecursive(head1, head2);
    display(newHead);
    return 0;
}


// // //Returning from call stack for input of 
// head1: 1 -> 3 -> 5
// head2: 2 -> 4 -> 6

/////////////////////
// Return to Call 5:

// result->next points to 6

// result is 5 -> 6

// Return 5 -> 6

// Return to Call 4:

// result->next points to 5 -> 6

// result is 4 -> 5 -> 6

// Return 4 -> 5 -> 6

// Return to Call 3:

// result->next points to 4 -> 5 -> 6

// result is 3 -> 4 -> 5 -> 6

// Return 3 -> 4 -> 5 -> 6

// Return to Call 2:

// result->next points to 3 -> 4 -> 5 -> 6

// result is 2 -> 3 -> 4 -> 5 -> 6

// Return 2 -> 3 -> 4 -> 5 -> 6

// Return to Call 1:

// result->next points to 2 -> 3 -> 4 -> 5 -> 6

// result is 1 -> 2 -> 3 -> 4 -> 5 -> 6

// Return 1 -> 2 -> 3 -> 4 -> 5 -> 6