#include <iostream>
using namespace std;

int leftOccurance(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int ans;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(key==arr[mid]){
            ans = mid;
            end = mid-1;
        }
        else if(key<arr[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int rightOccurance(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int ans;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(key==arr[mid]){
            ans = mid;
            start = mid+1;
        }
        else if(key<arr[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}


int main(){
    int list[6]={1,2,2,2,15,16};
    int elem;
    cin >> elem;
    int leftIndex = leftOccurance(list, 6, elem);
    int rightIndex = rightOccurance(list, 6, elem);
    // cout << leftIndex << " " << rightIndex << endl;
    cout << "Occurence of " << elem << " in array is: "<< (rightIndex-leftIndex)+1 << endl;
}