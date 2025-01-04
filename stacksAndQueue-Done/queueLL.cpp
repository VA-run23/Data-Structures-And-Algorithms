#include <bits/stdc++.h>
using namespace std;

class node{
    public: 
        int data; 
        node* next;
        node(int val){
            data=val;
            next=NULL;
        }
};

class Queue{
    node* front;
    node* back;

    public: 
        Queue(){//COnstructor
            front = NULL; 
            back = NULL;
        }

        void push(int x){
            node*  n= new node(x);//creating a new node, n is a pointer(node pointer) to it

            if(front ==NULL){//front = NULL means initially the queue is empty
            //So let two other node pointers back and front point the same node, that is first node
                back=n; 
                front =n;
                return;
            }
            back->next=n;//after creating node let the back pointing to the last node to point the newly created node 
            back=n;//Now let the back pointer to point the last node
        }

        void pop(){
            if(front==NULL){
                cout<<"Queue underflow, no elements to pop"<<endl;
                return;
            }
            node* todelete= front; 
            front =front->next;
            delete todelete;
        }

        int peek(){
            if(front==NULL){
                cout<<"No elements to peek"<<endl;
                return -1;
            }
            return front->data;
        }

        bool empty(){
             if(front==NULL){
                cout<<"Queue empty"<<endl;
                return true;
            }
            return false;
        }

};

int main(){
    Queue  q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.peek()<<endl;//1
    q.pop();
    cout<<q.peek()<<endl;//2
    q.pop();    
    cout<<q.peek()<<endl;//3
    q.pop();    
    cout<<q.peek();//not peek
    q.pop();//no elements to pop
    cout<<q.empty();


    return 0;
}