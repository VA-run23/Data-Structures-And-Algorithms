//Still not clear about pointer pointings and how all are gettting connected again 
//TC: O(n)
//22.4

#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

// Function to reverse the linked list in groups of size k
node* reverse(node* &head, int k) { 
    node* prePtr = NULL; // Previous pointer, initially NULL
    node* currPtr = head; // Current pointer, initially pointing to the head
    node* nextPtr; // Next pointer for traversal

    int count = 0; // Counter to keep track of the number of nodes reversed
    while (currPtr != NULL) { // Loop until the end of the list is reached
        nextPtr = currPtr->next; // Store the next node (moving forward)
        currPtr->next = prePtr; // Reverse the current node's pointer (pointing backwards)

        prePtr = currPtr; // Move the previous pointer to the current node (moving forward)
        currPtr = nextPtr; // Move the current pointer to the next node (moving forward)
        count++;
    }   

    if (nextPtr != NULL) { // If there are more nodes to reverse
        head->next = reverse(nextPtr, k); // Recursively reverse the next group of k nodes
    }
    return prePtr; // Return the new head of the reversed list
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
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    insertAtTail(head, 10);
    insertAtTail(head, 11);
    insertAtTail(head, 12);

    display(head);
    int k=7;
    node* newHead=reverse(head, k);
    display(newHead);


    return 0;
}


////Time complexity=O(n)
////output
// 1->2->3->4->5->6->NULL
// 2->1->4->3->6->5->NULL





// Let's walk through the `while` loop in detail for the linked list 1 -> 2 -> 3 -> 4 with `k = 2`.

// ### Initial State
// - `head` points to 1.
// - `prePtr = NULL`
// - `currPtr = 1`
// - `nextPtr` is undefined.
// - `count = 0`

// ### Step-by-Step Execution

// #### First Iteration

// 1. **Condition Check**:
//    - `currPtr != NULL` (1 is not NULL) and `count < k` (0 < 2), so the loop continues.

// 2. **Store the Next Node**:
//    - `nextPtr = currPtr->next;` 
//    - `nextPtr` points to 2.

// 3. **Reverse the Current Node's Pointer**:
//    - `currPtr->next = prePtr;` 
//    - Node 1's next is set to NULL (since `prePtr` is NULL).

// 4. **Move the Previous Pointer**:
//    - `prePtr = currPtr;` 
//    - `prePtr` now points to 1.

// 5. **Move the Current Pointer**:
//    - `currPtr = nextPtr;`
//    - `currPtr` now points to 2.

// 6. **Increment the Count**:
//    - `count++;`
//    - `count` becomes 1.

// ### List State
// - Partially reversed list: 1 (next is NULL)
// - Remaining list to process: 2 -> 3 -> 4
// - `prePtr` points to 1.
// - `currPtr` points to 2.
// - `nextPtr` points to 2.

// #### Second Iteration

// 1. **Condition Check**:
//    - `currPtr != NULL` (2 is not NULL) and `count < k` (1 < 2), so the loop continues.

// 2. **Store the Next Node**:
//    - `nextPtr = currPtr->next;` 
//    - `nextPtr` points to 3.

// 3. **Reverse the Current Node's Pointer**:
//    - `currPtr->next = prePtr;` 
//    - Node 2's next is set to 1 (since `prePtr` is 1).

// 4. **Move the Previous Pointer**:
//    - `prePtr = currPtr;` 
//    - `prePtr` now points to 2.

// 5. **Move the Current Pointer**:
//    - `currPtr = nextPtr;`
//    - `currPtr` now points to 3.

// 6. **Increment the Count**:
//    - `count++;`
//    - `count` becomes 2.

// ### List State
// - Partially reversed list: 2 -> 1 (next is NULL)
// - Remaining list to process: 3 -> 4
// - `prePtr` points to 2.
// - `currPtr` points to 3.
// - `nextPtr` points to 3.

// ### After the Loop

// - The loop exits because `count` has reached `k` (2).
// - The `prePtr` now points to the new head of this segment (2).

// #### Recursive Call

// 1. **Check for More Nodes**:
//    - `if (nextPtr != NULL)`: `nextPtr` points to 3, so the condition is true.
   
// 2. **Recursive Reverse**:
//    - `head->next = reverse(nextPtr, k);`
//    - The next segment (3 -> 4) will be reversed recursively with `k = 2`.

// #### Connecting Segments

// After the recursive call completes, the lists will be connected. 

// ### Final State
// - First segment: 2 -> 1 -> (points to the result of recursive call)
// - Recursive result: 4 -> 3 -> NULL

// Combining these:
// - Final list: 2 -> 1 -> 4 -> 3

// ### Output for 1 -> 2 -> 3 -> 4 with k = 2

// 1 -> 2 -> 3 -> 4 -> NULL

// Transformed into:

// 2 -> 1 -> 4 -> 3 -> NULL
