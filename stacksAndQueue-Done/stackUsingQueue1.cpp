
// 24.4
// pop method costly 
#include <bits/stdc++.h>
using namespace std;

class Stack {
    int N;
    queue<int> q1;
    queue<int> q2;
public:
    Stack() {
        N = 0;
    }

    void pop() {
        if (q1.empty()) {
            return;
        }
        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void push(int x) {
        q1.push(x);
        N++;
    }

    int top() {
        if (q1.empty()) {
            return -1;
        }
        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);
        q1.pop();

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return ans;
    }

    int size() {
        return N;
    }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.top() << endl; // Should print 4
    st.pop();
    cout<<st.size()<<endl;
    cout << st.top() << endl; // Should print 3
    st.pop();
    cout<<st.size()<<endl;

    cout << st.top() << endl; // Should print 2
    st.pop();
    cout<<st.size()<<endl;

    cout << st.top() << endl; // Should print 1
    st.pop();
    cout<<st.size()<<endl;

    cout << st.top() << endl; // Should print -1 (stack is empty)
    cout<<st.size()<<endl;
    
    return 0;
}
