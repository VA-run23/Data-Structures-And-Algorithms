//Done
//TC: 
//

#include <bits/stdc++.h>
using namespace std;

int prefixEvaluation(string s){
    stack<int > st;
    for(int i=s.length()-1; i>=0; i--){//Traversing from right to left
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

        switch(s[i]){
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(pow(op1, op2)); 
                break;
            }
        }
    }
    return st.top();
}

int main(){
    cout<<prefixEvaluation("-+7*45+20");
    return 0;
}