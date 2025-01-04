// class node{
// public:
//     int data;
//     node *next;
//     node(int val){
//         data = val;
//         next = NULL;
//     }
// };
// void display(node *head){
//     node *temp = head;
//     while (temp != NULL){
//         cout << temp->data;
//         temp = temp->next;
//     }
// }
// void insertAtTail(node *&head, int val){
//     node *n = new node(val);
//     if (head == NULL){
//         head = n;
//         return;
//     }
//     node *temp = head;
//     while (temp->next != NULL){
//         temp = temp->next;
//     }
//     temp->next = n;
// }

