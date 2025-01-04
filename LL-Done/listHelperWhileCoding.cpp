// class node{
// public:
//     int data;
//     node *next;
//     node(int val)
//     {
//         data = val;
//         next = NULL;
//     }
// };
// void display(node *head)
// {
//     node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << "->";
//         temp = temp->next;
//     }
//     cout << "NULL" << endl;
// }

// node *reverse(node *&head)
// {
//     node *prePtr = NULL;
//     node *currPtr = head;
//     node *nextPtr;
//     while (currPtr != NULL)
//     {
//         nextPtr = currPtr->next;
//         currPtr->next = prePtr;

//         prePtr = currPtr;
//         currPtr = nextPtr;
//     }
//     return prePtr;
// }

// void insertAtTail(node *&head, int val)
// {
//     node *n = new node(val);
//     if (head == NULL)
//     {
//         head = n;
//         return;
//     }
//     node *temp = head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = n;
// }

// node *reverseRecursive(node *&head)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }
//     node *newHead = reverseRecursive(head->next);
//     head->next->next = head;
//     head->next = NULL;
//     return newHead;
// }

// ////run time list creation through array
// int n;
// cin >> n;
// int arr[n];
// for (int i = 0; i < n; i++)
// {
//     cin >> arr[i];
// }
// for (int i = 0; i < n; i++)
// {
//     insertAtTail(head, arr[i]);
// }

// //length of LL
// int length(node* &head){
//     int l=0;
//     node* temp=head;
//     while(temp!= NULL){
//         l++; 
//         temp=temp->next;
//     }
//     return l;
// }
