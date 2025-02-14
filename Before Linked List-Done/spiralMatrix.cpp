//DONE
#include<iostream>
using namespace std;

int main(){
    int  n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            cin>>a[i][j];
        }
    }
    //Spriral order print 
    int rowStart=0, rowEnd=n-1, colStart=0, colEnd=m-1;
    while(rowStart<=rowEnd && colStart<=colEnd){
        //for rowStart
        for(int col=colStart; col<=colEnd; col++){
            cout<<a[rowStart][col]<<" ";
        }
        rowStart++;

        //for colEnd
        for(int row=rowStart;row<=rowEnd; row++){
            cout<<a[row][colEnd]<<" ";
        }
        colEnd--;
        //for row end
        for(int col=colEnd;col>=colStart;col--){
            cout<<a[rowEnd][col]<<" ";
        } 
        rowEnd--;
        //for colStart
        for(int row=rowEnd;row>=rowStart; row--){
            cout<<a[row][colStart]<<" ";
        }
        colStart++;
        cout<<endl;

    }
return 0;
}
// //Output
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9
// //Output
// 1 2 3 6 9 8 7 4 
// 5 