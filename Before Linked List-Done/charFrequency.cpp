//done
//TC : O(n)
////Namaste
#include<iostream>
#include<string>

using namespace std;

int main(){
    string s="heqoiadfafahiokmlhqhfnf";
    int freq[26];
    for(int i=0;i<26; i++){
        freq[i]=0;
    }
    for(int i=0; i<s.size(); i++)
        freq[s[i]-'a']++;//if s[i]='a' then at zeroth index its value will be increased by one//agar s[i] a hua toh 0 index pe ++ kardega, agar s[i] b hua to 1 index pe ++ hoga
    char ans='a';
    int max=0;
    for(int i=0; i<26; i++){
        if(freq[i]>max){
            max=freq[i];
            ans=i+'a';//is used to convert the index i back to the corresponding lowercase letter.
        }
    }
    cout<<ans<<":"<<max<<endl;
return 0;
}
// //output
// f:4