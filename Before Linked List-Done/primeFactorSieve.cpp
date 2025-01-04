//Done
////Namaste
#include<iostream>
#include<string>

using namespace std;
void primeFactor(int n){
    int spf[100]={0};
    for (int i=2; i<=n; i++){
        spf[i]=i;
    }
    for(int i=2; i<=n; i++){
        if(spf[i]==i){
            for(int j=i*i; j<=n; j+=i){//smallest number will be set first(then all its multiples) then the same number is not used again , it is ensured from if condition in next line
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
    while(n!=1){
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }
    
}
int main(){
    int n;
    cin>>n;
    primeFactor(n);
return 0;
}