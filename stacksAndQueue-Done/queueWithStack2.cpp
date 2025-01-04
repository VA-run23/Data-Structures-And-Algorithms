//Done
//TC: 
//

#include <bits/stdc++.h>
using namespace std;

class Queue{//queue can be defined if only <iostream> is included
    stack<int> s1;
     
    public:
        void push(int x){//TC: O(1)//Here we are defining the queue method by using stack method
            s1.push(x);
        }

        int pop(){//TC: O(n)
            if(s1.empty() ){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            int x=s1.top();
            s1.pop();
            if(s1.empty()){//base case
                return x;
            }
            int item=pop();//recursive calling 
            //there is difference between s1.pop() and pop()
            //The s1.pop() is operation of stack and pop() is the method defined in the Queue class
            s1.push(x);//after reaching the base case, push all the other elements back into the stack
            //This stepm of pushing back elements ensures that the order of elements in the stack is preserved.            return item;
            return item;   
        }

        bool empty(){//Empty of queue is determined by emptiness of the stack
            if(s1.empty()){
                return true;
            }
            return false;
        }

        // bool empty(){////A simplified version
        //     return s1.empty();
        // }

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