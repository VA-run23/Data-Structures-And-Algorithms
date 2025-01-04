/////8.6
//////Kadanes's algorithm approach, having time complexity O(n)
#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int currMax = a[0];
    int globalMax = a[0];

    for(int i = 1; i < n; i++){
        currMax = max(a[i], currMax + a[i]);
        if(currMax > globalMax){
            globalMax = currMax;
        }
    }
    cout << globalMax << endl;
    return 0;
}
