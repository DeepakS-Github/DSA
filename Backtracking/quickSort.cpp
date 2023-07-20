#include <iostream>
using namespace std;

int partiton(int arr[], int s, int e){
    int count = 0;
    for(int i=s; i<=e; i++){
        if(arr[s] > arr[i]){
            count++;
        }
    }
    int p = s+count;
    swap(arr[p],arr[s]);
    int index1=s, index2=e;
    while(index1!=p && index2!=p){
        if(arr[index1]>arr[p] && arr[index2]<arr[p]){
            swap(arr[index1], arr[index2]);
            index1++;
            index2--;
        }
        if(arr[index2]>arr[p]){
            index2--;
        }
        if(arr[index1]<arr[p]){
            index1++;
        }
    }
    return p;
}

void quickSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int p = partiton(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main(){
    int arr[5] = {5,4,3,2,1};
    quickSort(arr,0,4);
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
}