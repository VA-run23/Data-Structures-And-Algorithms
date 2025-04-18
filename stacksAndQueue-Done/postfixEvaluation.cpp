//Done
//TC: 
//
#include <bits/stdc++.h>
using namespace std;

int postfixEvaluation(string s){
    stack<int>st; 
    for(int i=0;i<s.length(); i++){//Traversing from left to right
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');//converting into integer
        }else{
            int op2=st.top();
            st.pop();
            int op1=st.top();
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
    cout<<postfixEvaluation("46+2/5*7+")<<endl;
    return 0;
}

//Pushing all the string characters to the stack
//whenever a operator is encountered the first two numbers are operated and the resulting value is stored is again pushed in the stack