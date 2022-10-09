#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(key==arr[mid]){
            return mid;
        }
        else if(key<arr[mid]){
            // Enter the left side to the mid of the array
            end = mid-1;
        }
        else{
            // Enter the right side to the mid of the array
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    int list[6]={1,2,5,9,15,16};
    int elem;
    cin >> elem;
    int a = binarySearch(list, 6, elem);
    cout << "Index of " << elem << " is " << a << endl;

}