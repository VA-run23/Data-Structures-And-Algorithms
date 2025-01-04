//25.5
//This program calculates the span of consecutive days for which the stock price is less than or equal to today's price, including today.
#include <bits/stdc++.h>
using namespace std;

vector<int>stockspan(vector<int>prices){
    vector<int>ans;
    stack<pair<int, int>>s;
    for(auto price: prices){
        int days=1;// Initialize the span for the current price as 1
        while(!s.empty() and s.top().first<=price){//only conecutive days are taken into account
            days+=s.top().second; 
            s.pop();
        }
        s.push({price, days}); // Can also be written using make_pair
        // This line pushes the current price and its calculated span onto the stack
       //NOTE: s.push({price, days}); this line ensures not to traverse the stack again
        ans.push_back(days); // Stores the calculated span for the current price in the answer vector
        // This line is used to append the span to the final answer list
      }
    return ans;
}

int main(){
    vector<int>a={100, 80, 60, 70,60, 75, 85};
    vector<int> res=stockspan(a);
    for(auto i: res){
        cout<<i<<" ";
    }
    cout<<endl;
        vector<int>b={100, 80, 60, 70,120, 75, 85};
    vector<int> res1=stockspan(b);
    for(auto i: res1){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
// //output
// 1 1 1 2 1 4 6 
// 1 1 1 2 5 1 2 
