//Done
//TC : O(n)
//////Character array finding word length
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();// reads up to n characters from the input stream (including spaces) into the character array arr
    char arr[n + 1];
    cin.getline(arr, n + 1);// reads up to n characters from the input stream (including spaces) into the character array arr

    int i = 0, currLen = 0, maxLen = 0, st=0,maxSt=0;
    while (1) {
        if (arr[i] == ' ' || arr[i] == '\0') {
            if (currLen > maxLen) {
                maxLen = currLen;
                maxSt=st;
            }
            currLen = 0;
            st=i+1;
        } else {
            currLen++;
        }
        if (arr[i] == '\0') {
            break;
        }
        i++;
    }

    cout << maxLen << endl;
    for(int i=0; i<maxLen; i++)
        cout<<arr[i+maxSt];
    return 0;
}
// //output
// 1234567 3456 24634573 245257389876543234567
// 21
// 245257389876543234567