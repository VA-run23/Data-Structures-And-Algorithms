//Done
//TC: 
//
//In this program we are just removing the elements from the queue logically but not physically
#include<iostream>
using namespace std;

#define n 20

class queue {
    int *arr; 
    int front; 
    int back;
public:
    queue() {
        arr = new int[n];//n is defined 20
        //In this program , since only one  queue is initialised only one time an array is formed
        front = -1;
        back = -1;
    }

    void push(int x) {
        if (back == n - 1) {
            cout << "Queue overflowed" << endl;
            return;
        }
        back++;//this makes the first time to move from -1 to 0th index
        //Back is incremented for each insertion
        arr[back] = x;

        if (front == -1) {//this makes the first time to move from -1 to 0th index
            front++;
        }
    }

    int pop() {
        if (front == -1 || front > back) {
            cout << "No elements in queue to pop" << endl;
            return -1; // Return a value to indicate error
        }
        int poppedValue = arr[front];
        front++;
        //Front is incremented for each deletion 
        return poppedValue;
    }

    int peek() {
        if (front == -1 || front > back) {
            cout << "No elements in queue to peek" << endl;
            return -1; // Return a value to indicate error
        }
        return arr[front];
    }

    bool empty() {
        if (front == -1 || front > back) {
            return true;
        }
        return false;
    }
};

int main() {
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.peek() << endl; // 1
    q.pop(); // dequeue 1
    cout << q.peek() << endl; // 2
    q.pop(); // dequeue 2
    cout << q.peek() << endl; // 3
    q.pop(); // dequeue 3
    cout << q.peek() << endl; // 4
    q.pop(); // dequeue 4
    cout << q.empty() << endl; // 1 (true)

    return 0;
}
