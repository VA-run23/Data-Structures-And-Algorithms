//DONE
//This program only removes the immediate duplicates only
///TC: O(n)

#include <bits/stdc++.h>
using namespace std;

string removeDup(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];//store previous character of the string in this recursive call
    string ans=removeDup(s.substr(1));
    if(ch==ans[0]){//compares the current character with the previous one, if found same it just returns a single of them
        return ans;
    }
    return (ch+ans);//if both previous and the current character are different , combine them and return
}
int main(){
    string s;
    cin>>s;
    cout<<removeDup(s)<<endl;
return 0;
}

////INPUT: 
// abcdcba
///OUTPUT:
// abcdcba

//INPUT: 
// aabbcc
////Output 2
// abc