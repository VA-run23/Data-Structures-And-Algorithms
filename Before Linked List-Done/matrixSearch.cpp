//searching in sorted matrix
////Done
//TC : O(m+n)
#include<iostream>
using namespace std;
int main(){
    int n,m,target;
    cin>>n>>m;
    int mat[n][m];
    cin>>target;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }
    int r=0, c=m-1;
    bool found=false;
    while(r<n && c>=0){
        if(mat[r][c]==target){
            found=true;
            break;
        }
        if(mat[r][c]>target){
            c--;
        }else{
            r++;
        }
    }
    if(found){
        cout<<"Element found"<<endl;
    }else{
        cout<<"Element doesn't exist"<<endl;
    }
return 0;
}
////Output
// 3   
// 3
// 1
// 1  2  3
// 4  5  6
// 7  8  9

// Element found