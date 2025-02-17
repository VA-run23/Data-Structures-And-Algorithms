//DONE
//TC : O(2^n)   
//follows fibonacci sequence
#include <bits/stdc++.h>
    using namespace std;

    int tilingWays(int n){
        if(n==0 || n==1){
            return n;
        }
        return tilingWays(n-1)+tilingWays(n-2);
    }
    int main(){ 
        int n;
        cin>>n;
        cout<<tilingWays(n)<<endl;
        return 0;
    }   
    /////taling for 2rows and n columns, with each tail having 2*1 capacity, 
    ////for 2*4, only 3 ways are possible 
    ////1)placing all horizontal
    ////2)placing all in vertical
    ////3)placing 2 in vertical and 2 in horizontal
    //////don't bother about the position
