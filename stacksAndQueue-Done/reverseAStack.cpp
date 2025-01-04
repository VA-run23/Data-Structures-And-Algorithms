//Done
//TC: 
//
#include <bits/stdc++.h>
using namespace std;

// Function to insert an element at the bottom of a stack
void insertAtBottom(stack<int> &st, int ele) {
    // Base case: If stack is empty, push the element
    if (st.empty()) {
        st.push(ele);
        return;
    }

    // Recursive case: Pop the top element and call insertAtBottom
    int topEle = st.top();
    st.pop();
    insertAtBottom(st, ele);//the ele value will remains same until it is added to the bottom,

    // Push the top element back after inserting the new element at the bottom
    st.push(topEle);
}
// it is like store the top most element in topEle 
// and insert the ele at bottom with recursive function call
// after inserting the ele at bottom(ie after reaching the base cawe)
// again push the ele to the stack

// //Inshort
// Store the Top Element:
// Recursive Call to Insert at Bottom:
// Push Elements Back:

// Function to reverse a stack
void reverse(stack<int> &st) {
    // Base case: If stack is empty, do nothing
    if (st.empty()) {
        return;
    }

    // Pop the top element and reverse the remaining stack
    int ele = st.top();
    st.pop();
    reverse(st);

    // Insert the popped element at the bottom of the reversed stack
    insertAtBottom(st, ele);
}
 

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<"Original stack"<<endl;

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }

    ////uncomment these to display the original as well as reversed stack

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverse(st);
  cout<<"Reversed stack"<<endl;
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}