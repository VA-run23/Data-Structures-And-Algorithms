//done
//Each call to transform iterates through the entire string, performing a constant amount of work for each character.
//Since each transform call runs in linear time, the overall time complexity remains O(n).

#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

int main(){
    string s="DateqQRWGFfsfgsfSDFGsfgSDfgSDfgSfg"; 
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout<<s<<endl;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout<<s<<endl;
return 0;
}