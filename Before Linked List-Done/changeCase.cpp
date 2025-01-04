//done
//TC : O(n)

////To upper or lower case of strings
#include<iostream>
#include<string>
using namespace std;

int main(){
    string str="ieDweDGteGEvGegeOhaSFSfgsUff";

    //converting to uppercase
    for(int i=0; str[i]!='\0'; i++){
        // if(int(i)<97)
        if(str[i]>='a' && str[i]<='z')
            str[i]-=32;
    }
    for(int i=0; str[i]!='\0'; i++){
        cout<<str[i];
    }
    cout<<endl;
     //converting to lowercase
    for(int i=0; str[i]!='\0'; i++){
        // if(int(i)>97)
        if(str[i]>='A' && str[i]<='Z')
            str[i]+=32;
    }
    for(int i=0; str[i]!='\0'; i++){
        cout<<str[i];
    }
    cout<<endl;

return 0;
}