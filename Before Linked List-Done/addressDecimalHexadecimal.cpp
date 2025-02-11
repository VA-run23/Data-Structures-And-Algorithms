// /Namaste
#include<iostream>
#include<string>
using namespace std;
int main(){
int *ptr;
int a;
ptr=&a;
printf("Address of variable a in hexadecimal is: %p\n",ptr );
printf("Address of variable a in decimal is: %d",ptr );
return 0;
}
//Output
// Address of variable a in hexadecimal is: 0061FF18
// Address of variable a in decimal is: 6422296

//Reason: 0061FF18 in hexadecimal is equal to 6,422,296 in decimal.