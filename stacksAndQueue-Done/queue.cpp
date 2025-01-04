////test 23
//Done
//TC: 
//
#include<iostream>
using namespace std;

#define n 20

class queue{
    int * arr; 
    int front ; 
    int back;
    public:
    queue(){
        arr= new int[n];
        front =-1;
        back=-1;
    }
    void push(int x){//first check whether the queue has space or not 
        if(back==n-1){
            cout<<"Queue overflowed"<<endl;
            return ;
        }
        back++;
        arr[back]=x;

        if(front ==-1){
            front ++;
        }
    }
   
    int pop() {
        if (front == -1 || front > back) {
            cout << "No elements in queue to pop" << endl;
            return -1; // Return a value to indicate error
        }
        int poppedValue = arr[front];
        front++;
        return poppedValue;
    }

    int peek(){
         if(front ==-1 || front> back){
            cout<<"No elements in queue to peek"<<endl;
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(front ==-1 || front>= back){
            cout<<"EMpty queue: ";
            return true;
        }
        return false;
    }
};

int main() {
    queue q;
    //Enquing 5 elements into the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.peek() << endl;//1
    q.pop();//dequeue 1
    cout << q.peek() << endl;//2
    q.pop();  //dequeue 2
    cout << q.peek() << endl;//3
    q.pop();  //dequeue 3
    cout << q.peek() << endl;//4
    q.pop();//dequque 4
     cout << q.peek() << endl;//5
    q.pop();//dequque 5
    cout << q.peek();//fail condition
    q.pop();//fail condition
    cout << q.empty()<< endl;//1
    return 0;
}
// //Output
// 1
// 2
// 3
// 4
// 5
// No elements in queue to peek
// -1No elements in queue to pop
// EMpty queue: 1
