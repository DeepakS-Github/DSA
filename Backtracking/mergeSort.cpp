#include <iostream>
using namespace std;


void merge(int arr[], int s, int e){
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;
    int arr1[len1], arr2[len2];
    int index = s;
    for(int i=0; i<len1; i++){
        arr1[i]=arr[index];
        index++;
    }
    for(int i=0; i<len2; i++){
        arr2[i]=arr[index];
        index++;
    }
    index = s;
    int index1=0, index2=0;
    while(index1<len1 && index2<len2){
        if(arr1[index1]>arr2[index2]){
            arr[index++] = arr2[index2];
            index2++;
        }
        else if(arr2[index2]<=arr2[index2]){
            arr[index++] = arr1[index1];
            index1++;
        }
    }
    while(index1<len1){
        arr[index++] = arr1[index1++];
    }
    while(index2<len2){
        arr[index++] = arr2[index2++];
    }
}

void mergeSort(int arr[], int s, int e){
    if(s==e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}


int main(){
    int arr[5] = {4,2,1,5,3};
    mergeSort(arr, 0, 4);
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
}