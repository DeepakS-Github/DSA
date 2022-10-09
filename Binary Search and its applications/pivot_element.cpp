#include <iostream>
using namespace std;

int findPivot(int arr[], int size){
    int start = 0;
    int end = size-1;
    while(start<end){
        int mid = start + (end-start)/2;
        if(arr[0]<=arr[mid]){
            start = mid+1;
        }
        else{
            end = mid;
        }
    }
    return start;
}

int main(){
    int list[9] = {5,6,7,8,9,10,1,3,4};
    int pivotIndex = findPivot(list, 9);
    cout << pivotIndex << endl;
}