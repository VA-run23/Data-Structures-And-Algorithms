//Done
 ////what is the maximum number of pages/boards that a painter have to paint so that it requires less number of painters


//The problem is about allocating n boards to m painters such that the time taken to paint all the boards is minimized. 
//Each painter paints a contiguous segment of boards,
// and the time taken by a painter is the total number of pages of the segment of boards assigned to them.
#include <bits/stdc++.h>
using namespace std;

int findFeasible(int boards[], int n, int limit) { // 'n' is the number of boards, 'limit' is the maximum length of boards that can be painted by a painter
    int sum = 0, painters = 1;
    for(int i = 0; i < n; i++) {
        sum += boards[i];
        
    
        if(sum > limit) {
        /* 
        The if(sum > limit) condition checks whether the total number of pages assigned 
        to the current painter exceeds the given limit. If it does, it means we need 
        to allocate a new painter for the next set of boards because the current painter 
        has reached their maximum allowed pages.
        */
            sum = boards[i]; // Start a new sum for the next painter
            painters++; // Increment the painter count
        }
    }
    return painters;
}



int paintersPartition(int boards[], int n, int m){
    int totalLength = 0, k = 0;
    for(int i=0; i<n; i++){
        totalLength += boards[i];
    }
    int low = k, high = totalLength;
    while (low < high)
    {
        int mid = (low + high )/ 2;
        int painters = findFeasible(boards, n, mid);
        if(painters <= m){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    int arr[] = {10, 20, 30, 40};
    int n=4, m = 2;//n number of boards and m number of painters
    cout<<"Minimum time to paint boards: "<< paintersPartition(arr, n , m);//what is the maximum number of pages/boards that a painter have to paint so that it requires less number of painters
    cout<<endl;
    return 0;
} 