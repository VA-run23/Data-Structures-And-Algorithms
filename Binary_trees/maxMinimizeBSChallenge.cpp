//Done
//29.1
//Binary search challenge
//Given is an array with n elements that represents n positions along a straight line. Find K elements such that the minimum distance between any 2 elements is the maximum possible
//Maximize the minimum distance possible(between the elements of the array)
//In this problem, binary search is used to find the largest minimum distance between any two of the k elements.
#include <bits/stdc++.h>
using namespace std;

bool isFeasible(int mid, int arr[], int n, int k ){
    int pos = arr[0], elements = 1;//explain this line
    for(int i=1; i<n; i++){
        if(arr[i]-pos >= mid){//checking if the distance between the two elements is greater than the mid
            pos = arr[i];
            elements++;
            if(elements == k){
                return true;
            }
        }
    }
    return false;
}

int largestMinDist(int arr[], int n , int k){//n is length of array, k is the minimum numbers required
    sort(arr, arr+n);
//In the context of sorting an array, you're passing the starting and ending addresses (or pointers) to the sort function

// arr           arr + n
//   |               |
//   v               v
//  [3, 1, 4, 1, 5, 9]

    int result = -1, left = 1, right = arr[n-1];//basically left and right are the indexes to calculate the mid

    while(left <right){
        int mid = (left + right) / 2;
        if(isFeasible(mid, arr, n ,k )){//for larger feasible distance(which is mid in this case)      
            result = max(result, mid);//if mid is a bigger number than result, then search for the next bigger number
            left = mid+1;
        }else {//then we will search in left
            right = mid;//if mid is not a feasible distance, then we will search in left
        }
    }
    return result;
}

int main(){
    int arr[] = {1,2,8, 4, 9};
    int arr1[] = {1,2,5, 7, 11, 12};
    int n = 5;//Size
    int k = 3;//Number of values
    int n1 = 6;
    int k1 = 3;
    cout<<" largest min distance is: "<<largestMinDist(arr, n,k)<< endl;
    cout<<" largest min distance is: "<<largestMinDist(arr1, n1,k1)<< endl;
    return 0;
}

// Algorithm
// 1. Sort the array in ascending order.
// 2. Use binary search to find the largest minimum distance:
//    a. Initialize left and right bounds.
//    b. Pick the middle element as the potential result.
//    c. Check if this middle element is a feasible distance using the isFeasible function.
//    d. If feasible, update the result and search the right half of the array for a larger minimum distance.
//    e. If not feasible, search the left half of the array for a smaller distance.
// 3. Return the largest minimum distance found.
