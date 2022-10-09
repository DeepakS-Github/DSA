#include <iostream>
using namespace std;

int minElem(int arr[], int size){
    int min = INT_MAX;
    for(int i=0; i<size; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}

int maxElem(int arr[], int size){
    int max = INT_MIN;
    for(int i=0; i<size; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int len;
    cin >> len;
    int list[100]={0};
    for(int i=0; i<len; i++){
        cin >> list[i];
    }
    int minimum = minElem(list, len);
    int maximum = maxElem(list, len);
    cout << minimum << " " << maximum << endl;
} 