//33.3
//Use of lambda functions
// take the activity which ends first
// sort the activity with respect to end times
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(a, n ,i) for (int i=a; i<n; i++)//some changes done here only
#define ff first
#define ss second 
#define setBits(x) __builtin_popcount(x)


int main(){
    int n;
    cin>>n;
    vector<vector<int>> v;
    rep(0, n, i){
        int start, end;
        cin>>start>>end;
        v.push_back({start, end});//{start, end} makes the vector

    }

    //sorting using lamba function
    sort(v.begin(),v.end(), [&](vector<int> &a, vector<int>& b){//In summary, this code sorts the vector v based on the second element of each inner vector in ascending order. 

// sort(v.begin(), v.end(), ...): This is the std::sort function. It sorts the elements in the range v.begin(), v.end()).
// [&: This is a lambda function used as the custom comparison function. The & captures all external variables by reference, allowing the lambda to access variables outside its scope.
// vector<int> &a, vector<int>& b: These are the parameters of the lambda function, representing two elements (which are vectors of integers) from the vector v that are being compared.
// return a[1] < b[1];: This is the body of the lambda function. It compares the second elements (a[1] and b[1]) of the two vectors. The function returns true if the second element of a is less than the second element of b, meaning a should come before b in the sorted order.

        return a[1] < b[1];
    });
    int take = 1;
    int end = v[0][1];
    for(int i=1; i< n; i++){
        if(v[i][0] >= end){
            take++;
            end = v[i][i];
        }
    }
    cout<<take<<"\n"<<endl;

    return 0;
} 


// //Input
// 3
// 10 20
// 12 15
// 12 12

// //Output
// 2


////Failing for this
// 4
// 10 20
// 12 15
// 12 12
// 20 30

////expected output is 2 but getting 3
