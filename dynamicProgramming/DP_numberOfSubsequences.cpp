//35.13
//Important
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define vpi vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) __builtin_popcount(x)//counts the number of set bits (1s) in the binary representation of x


const int N = 1e5+2, MOD = 1e9+7;


int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int e = 1, a = 0, ab = 0, abc = 0;
    for(int i = 0; i<n; i++){
        if( s[i] == 'a'){
            a += e;
        } else if (s[i]== 'b'){
            ab += a;
        } else if(s[i] == 'c'){
            abc += ab;
        }else if(s[i] == '?'){
            abc = 3* abc + ab;
            ab = e* ab + a;
            a = 3*a + e;
            e = 3 * e;
        }
    }
    cout<<abc<<endl;

    return 0;
} 