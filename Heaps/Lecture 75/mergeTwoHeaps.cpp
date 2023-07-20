#include <iostream>
#include <vector>
using namespace std;

void heapify(int index, vector<int> &arr, int size){
    int i = index;
    int leftChildIndex = 2*i;
    int rightChildIndex = 2*i+1;
    while(leftChildIndex<=size && rightChildIndex<=size && (arr[leftChildIndex]>arr[i] || arr[rightChildIndex]>arr[i])){
        if(arr[leftChildIndex]>=arr[rightChildIndex]){
            swap(arr[i], arr[leftChildIndex]);
            i = leftChildIndex;
        }
        else{
            swap(arr[i], arr[rightChildIndex]);
            i = rightChildIndex;
        }
        leftChildIndex = 2*i;
        rightChildIndex = 2*i+1;
    }

    if(leftChildIndex==size && arr[leftChildIndex]>arr[i]){
        swap(arr[leftChildIndex], arr[i]);
    }
}

void buildHeap(int size, vector<int> &arr){
    for(int i=size/2; i>=1; i--){
        heapify(i, arr, size);
    }
}

int main(){
    vector<int> h1 = {7,5,4,2,1};
    vector<int> h2 = {9,3,8};

    vector<int> h;
    h.push_back(-1);
    for(int i=0; i<h1.size(); i++){
        h.push_back(h1[i]);
    }
    for(int i=0; i<h2.size(); i++){
        h.push_back(h2[i]);
    }

    buildHeap(h.size()-1, h);

    for(int i=1; i<h.size(); i++){
        cout << h[i] << " ";
    }
}