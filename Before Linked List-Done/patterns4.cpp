////Namaste
#include<iostream>
#include<string>
using namespace std;
int main(){
    int m,n,i,j,k;


///////Zig-zag pattern
cin>>n;
for(int i=1; i<=3;i++){
    for(int j=1; j<=n; j++){
        if(((i+j)%4==0)|| (i==2 && j%4==0)){
            cout<<"* ";
        }else{
            cout<<"  ";
        }
    }
    cout<<"\n";
}









// //////Butterfly pattern
// cin>>n;
//  for(int i=1; i<=n; i++){
//     for(int j=1; j<=i; j++){
//         cout<<"*";
//     }
//     int space=2*n-2*i;
//     for(int j=1; j<=space; j++){
//         cout<<" ";
//     }
//     for(int j=1; j<=i; j++){
//         cout<<"*";
//     }
//    cout<<"\n";
//  }
//  for(int i=n; i>=1; i--){
//     for(int j=1; j<=i; j++){
//         cout<<"*";
//     }
//     int space=2*n-2*i;
//     for(int j=1; j<=space; j++){
//         cout<<" ";
//     }
//     for(int j=1; j<=i; j++){
//         cout<<"*";
//     }
//    cout<<"\n";
//  }





// //////pattern of Floyd's triangle
// cin>>m;
// int num=1;
// cout<<"The pattern generated is: "<<endl;
// for(i=1;i<=m; i++ ){//loop for number of rows
//     for(j=1;j<=i; j++){ //loop to print number
//         cout<<num<<" " ;
//     num++;
// }
//     cout<<"\n";
// }




// ////Left half pyramid using number repetation
// cin>>m;
// cout<<"The pattern generated is: "<<endl;
// for(i=1;i<=m; i++ ){
//     for(j=1;j<=i; j++){ 
//         cout<<i;
//     }
//     cout<<"\n";
// }






//////Left half pyramid using numbers repetation in reverse order
// cin>>m;
// cout<<"The pattern generated is: "<<endl;
// for(i=m;i>=1; i-- ){
//     for(k=m; k>=i; k--){ 
//         cout<<i;
//     }
//     cout<<"\n";
// }




// ////Left half pyramid
// cin>>m;
// for(i=m;i>=1; i-- ){
//     for(j=1; j<=i; j++){
//         cout<<" ";
//     }

//     for(k=m; k>=i; k--){ 
//         cout<<"*";
//     }

//     cout<<"\n";
// }



///////////Left half pyramid can also be constructed by this code
// cin>>n;
// for(int i=1; i<=n;i++){
//     for(int j=1; j<=n; j++){
//         if(j<=n-i){
//             cout<<" ";
//         }else{
//             cout<<"*";
//         }
//     }
//   cout<<"\n";

// }


// ////inverted half pyramid
// cin>>m;
// for(i=m; i>=1; i--){
//     for(int j=i;j>=1; j--){
//         cout<<"*";
//     }
//     cout<<"\n";
// }


// ////HOLLOW RECTANGULAR PATTERN
// cin>>m>>n;
// for (int i = 1; i<= m; i++){
//     for(int j=1; j<=n; j++){
//         if(i==1 || i==m || j==1 || j==n){
//             cout<<"*";
//         }
//         else{
//             cout<<" ";
//         }
//     }
//     cout<<"\n";
// }


////REGULAR RECTANGULAR PATTERN
// cin>>m>>n;
// for(i=1; i<=m; i++){
//     for(int j=1;j<=n; j++){
//         cout<<"*";
//     }
//     cout<<"\n";
// }
return 0;
}