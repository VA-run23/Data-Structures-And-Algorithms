//Done
//TC: 
//
//approach 1

#include <bits/stdc++.h>
using namespace std;

class Queue{//queue can be defined if only <iostream> is included
    stack<int> s1;
    stack<int> s2;
     
    public:
        void push(int x){//TC: O(1)
            s1.push(x);
        }

        int pop(){//In the context of this implementation, s1 is the primary stack used for the main operations of the queue, while s2 is used as a temporary stack to reverse the order of elements when needed.

            if(s1.empty() and s2.empty()){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            int topVal=s2.top();//this will store the last element in s1 which was first pushed
            //and we are returning it
            s2.pop();
            return topVal;
        }

        bool empty(){
            if(s1.empty() and s2.empty()){
                return true;
            }
            return false;
        }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    cout<<q.pop()<<"\n";
    q.push(5);
    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";
    return 0;
}