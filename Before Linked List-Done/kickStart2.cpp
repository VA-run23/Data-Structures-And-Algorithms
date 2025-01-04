//Done
//TC : O(n)
////record broker
//a day is record broker when it has most numbers of visitors than previous recorded max and the day next of the current day has less number of visitors
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of days";
    cin>>n;
    int a[n+1];
    cout<<"Enter the number of visitors for respective days: "<<endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n]=-1;// handling the edge case for last day of record ,edge case is handled by taking value of number of visitors to -1, which is not possible
    if(n==1){
    cout<<"1"<<endl;
    return 0;
    }
    int ans=0;//record days
    int mx=-1;//max visitors
    for(int i=0; i<n; i++){
        if(a[i]>mx && a[i]>a[i+1]){ // Check if the current day's visitors are greater than the previous maximum and the next day's visitors
            ans++;
        }
        mx=max(mx,a[i]);
    }
    cout<<ans<<endl;
    return 0;
}
