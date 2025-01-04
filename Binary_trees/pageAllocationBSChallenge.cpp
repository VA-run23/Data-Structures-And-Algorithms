//Done
//29.2
//Important
//This code solves the problem of allocating minimum pages to m students,
// such that the maximum number of pages assigned to a student is minimized.
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int min) { // 'min' is the maximum number of pages a student can be allocated
    int studentsReq = 1, sum = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > min) {
            return false; // If any single book has more pages than 'min', it's impossible to allocate that book under the current 'min' constraint, so return false
        }
        if(sum + arr[i] > min) { // If adding the current book's pages exceeds 'min'
            studentsReq++; // Increment the number of students required
            sum = arr[i]; // Start a new sum for the next student
            if(studentsReq > m) {
                return false; // If the number of students required exceeds the number of available students, return false
            }
        } else {
            sum += arr[i]; // Add the current book's pages to the current student's total
        }
    }
    return true; // If the function completes, it means the allocation is possible under the given 'min' constraint
}


int void allocateMinimumPages(int arr[], int n, int m){
    int sum = 0;
    if(n < m){
        return -1;//no appropriate solution
    }
    for(int i=0; i<n; i++){
        sum+= arr[i];
    }
    int start = 0, end = sum, ans = INT_MAX;//we are finding the minmum value of ans
    while(start <= end){
        int mid = (start + mid)/2;
        if(isPossible(arr, n,m, mid)){
            ans = min(ans, mid);
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {12, 34, 67, 90};
    int n = 4;//number of books
    int m = 2;//number of students
    cout << "THe minimum no of pages: "<< allocateMinimumPages(arr, n, m) << endl;
        return 0;
}