//33.6 
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) __builtin_popcount(x)

int main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int, int> > a(n);
        for(int i =0; i< n; i++){
            cin>>a[i].ff>>a[i].ss;
        }
        int l, p;
        cin>>l >> p;
        for(int i = 0; i< n; i++){
            a[i].ff =l- a[i].ff; 
        }
        sort(a.begin(), a.end());
        int ans = 0;
        int curr = p;
        priority_queue<int, vector<int> > pq;
        bool flag = 0;
        for(int i =0; i< n; i++){
            if(curr >= l){
                break;
            }
            while(curr <a[i].ff){
                if(pq.empty()){
                    flag = 1; 
                    break;
                }
                ans++; 
                curr += pq.top();
                pq.pop();
                
            }
            if(flag){
                break;
            }
            pq.push(a[i].ss);
        }
        if(flag){
            cout<<"-1"<<endl;
            continue;
        }
        while(!pq.empty() && curr < l){
            curr += pq.top();
            pq.pop();
            ans++;
        } 
        if(curr< l){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
    return 0;
}

// // Input
// 4  
// 4  4
// 5 2
// 11  5
// 15 10 
// 25 10

// //Output
// 2