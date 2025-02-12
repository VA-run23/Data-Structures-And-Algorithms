//done
//// the overall time complexity is O(n)
#include <bits/stdc++.h>
using namespace std;

bool sorted(int arr[], int n){
    if(n==1){//thus, the last recursive call always returns true
        return true;
    }
    bool restArray=sorted(arr+1, n-1);///arr+1 points to next element of the array
    return (arr[0]<arr[1] && restArray);
    /*
    return (arr[0] < arr[1] && restArray);
    // If arr[0] < arr[1], the function proceeds to check the rest of the array (restArray).
    // restArray represents the result of the recursive call for the remaining elements.
    // The && (logical AND) operator ensures both conditions must be true for the entire expression to be true.
    // If arr[0] is not less than arr[1], the expression arr[0] < arr[1] evaluates to false.
    // As a result, the entire expression evaluates to false, indicating the array is not sorted.
    // If any value fails the condition of arr[0] < arr[1], false is returned, 
    // and the && operator continues to propagate the false result through the recursive calls.
    */
    }
int main(){
    int arr[7]={1,2,0,4,5,24,4234};
    int arr1[7]={1,2,3,4,5,6,7};
    cout<<sorted(arr, 7)<<endl;
    cout<<sorted(arr1, 7)<<endl;
return 0;
}

// //output
// 0
// 1
// The second argument 7 correctly matches the length of the array. However, if you were to call it with a different value, like 8 or 6, it would be problematic.
// If the value is greater than the array length (e.g., 8): The function will try to access elements beyond the end of the array, leading to undefined behavior.
// If the value is less than the array length (e.g., 6): The function will only check the first 6 elements, ignoring the rest of the array.