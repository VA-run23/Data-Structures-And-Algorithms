//Done
#include <bits/stdc++.h>
using namespace std;

class node{//node is an object consisting of attributes data and pointer next and a constructor function
    public:
    int data; 
    node* next;//A pointer to the next node in the list.
    node(int val){// Constructor that initializes the node with a value and sets the next pointer to NULL.
        data=val;
        next=NULL;
    }
};

//first create a node(and put the data or  value) then point it to the first node of the current list(that node can be accessed through head) of the list then change the head to the current (newly created) node
void insertAtHead(node* &head, int val){
    node* n=new node(val);//: Creates a new node with the given value.
    n->next=head;//Points the new node’s next to the current head.
    //newly created node is pointing to the list head, thus n of next points to the head
    head=n;
}

void insertAtTail(node* &head , int val){
    node*n =new node(val);//naya node named n will be created and its data field will be having the val
    
    if(head==NULL){// Checks if the list is empty.
        head = n;//n will be the first node , head is pointing to n then will the marked line will be executed?
        return;
    }

    node* temp=head;// Temporary pointer to traverse the list.
    while(temp->next!=NULL){//to reach last element or index
        temp=temp->next; //Sets the last node’s next to the new node.
    }
    temp->next=n;//explain this
}

void deletion(node* &head, int val){
    if(head == NULL){//if the link list is empty
        return;
    }

    if(head->next==NULL){
        deleteAtHead(head);
        return ;
    }
    node*temp=head;
    while(temp->next->data!= val){
        temp=temp->next;//loop to reach that element
    }
    node* toDelete= temp->next;
    temp->next=temp->next->next;//changing link
    delete toDelete;
}

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;//it's necessary to delete to prevent data leak
}

void display(node* head){
    node* temp=head; //we could have used head also instead of temp
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp=temp->next;//Moves to the next node.
    }
    cout<<"NULL"<<endl;
}

bool search(node * head, int key){
    node* temp=head;//This line assigns the address of head to temp. So, temp points to the same node as head at the start.
    while(temp!=NULL){//if temp!=key then if the key is not in the list it would be an infinite loop
        if(temp->data==key){
            return 1;
        }
        temp=temp->next;//This line moves the temp pointer to the next node in the list.
    }//In the line temp=temp->next;, the temp pointer is updated to store the address of the next node, which is stored in the next member of the current node. This allows temp to move to the next node in the linked list.
    return false;
}

int main(){
    node* head=NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    // display(head);
    // insertAtHead(head,7);
    // insertAtHead(head,'X');//ASCII Value of the char will be saved as class defined for int
    display(head);
    // deletion(head, 3);
    // cout<<search(head, 3);
    deleteAtHead(head);
    display(head);

    return 0;
}

//When you create new nodes using new node(val), the memory for these nodes is allocated dynamically from the heap. The exact location in memory where this allocation happens can vary each time the program runs.
//Address Space Layout Randomization (ASLR): Modern operating systems use a security feature called ASLR, which randomizes the memory addresses used by a program each time it runs. This makes it harder for malicious code to predict the location of specific data structures in memory.