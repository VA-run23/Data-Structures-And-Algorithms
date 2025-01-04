//Learn again

//25.3
#include <bits/stdc++.h>
using namespace std;

int rain_water(vector<int> a){
    stack<int> st; 
    int n=a.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        while(!st.empty() and a[st.top()]<a[i]){//till top element of the stack is lesser than current element
            int cur=st.top(); 
            st.pop(); 
            if(st.empty()){
                break;
            }
            int diff=i-st.top() -1;//This distance diff is used to determine the width of the water trapped between the two bars.
            ans+=(min(a[st.top()], a[i]) -a[cur])*diff;
        }
    st.push(i);
    }
    return ans;
}

int main(){
    vector<nt> a={0,1,0, 2,1,0,1,3,2,1,2,1};
    cout<<rain_water(a);
    //Outputs total water stored not only maximum
    return 0;
}


// int diff = i - st.top() - 1;
// This line calculates the horizontal distance between the current bar and the bar at the new top of the stack after popping.
// i is the current index in the iteration, representing the position of the current bar.

// st.top() gives the index of the new top element of the stack after popping the current top.

// i - st.top() calculates the number of bars between the current bar and the new top of the stack.

// - 1 is subtracted to get the actual number of bars between them, excluding the current bar and the bar at st.top().