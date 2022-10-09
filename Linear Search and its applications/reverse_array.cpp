#include <iostream>
using namespace std;

void printArr(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}

void revArr(int arr[], int size){
    int start = 0;
    int end = size-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    printArr(arr, size);
}

int main(){
    int len;
    cin >> len;
    int list[len];
    for(int i=0; i<len; i++){
        cin >> list[i];
    }
    revArr(list, len);
}