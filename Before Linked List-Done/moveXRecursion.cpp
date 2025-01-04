#include <bits/stdc++.h>
using namespace std;

string moveAllX(string s,char x){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string ans=moveAllX(s.substr(1), x);
    if(ch==x){
    return(ans+ch);//// If the first character is equal to `x`, append it to the result of the recursive call
    }
    return(ch+ans);//// Otherwise, prepend it to the result of the recursive call
}
int main(){
    string s;
    cout<<"Enter a string without any spaces: ";
    cin>>s;
    char x;
    cout<<"Enter a character that you want to move to the end of the string: ";
    cin>>x;
    cout<<moveAllX(s,x);
    return 0;
}
// output
// Enter a string without any spaces: afadfafasasdfafafafaaaaaaaaffaffa
// Enter a character that you want to move to the end of the string: a
// fdffssdffffffffaaaaaaaaaaaaaaaaaa