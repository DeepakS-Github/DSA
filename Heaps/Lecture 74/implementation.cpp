#include <iostream>
#include <vector>
using namespace std;


class Heap{
    public:
    vector<int> arr;
    int index;

    Heap(){
        arr.push_back(-1);
        index = 0;
    }
    
    void insert(int data){
        index++;
        arr.push_back(data);
        int i = index;
        int parent = i/2;
        while(i!=1 && arr[parent]<arr[i]){
            swap(arr[parent], arr[i]);
            i = parent;
            parent = i/2;
        }
    }

    void deletion(){
        if(index==0){
            cout << "Heap is empty" << endl;
            return;
        }
        swap(arr[1], arr[index]);
        index--;
        if(arr[index]!=arr[1]){
            int i = 1;
            int leftChildIndex = 2*i;
            int rightChildIndex = 2*i+1;
            while(leftChildIndex<=index && rightChildIndex<=index && (arr[leftChildIndex]>arr[i] || arr[rightChildIndex]>arr[i])){
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

            if(leftChildIndex==index && arr[leftChildIndex]>arr[i]){
                swap(arr[leftChildIndex], arr[i]);
            }
        }
    }

    void print(){
        if(index==0){
            cout << "Heap is empty" << endl;
            return;
        }        
        for(int i=1; i<=index; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


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

void buildHeap(int index, vector<int> &arr){
    for(int i=index/2; i>=1; i--){
        heapify(i, arr, index);
    }
}


void heapSort(vector<int> &arr, int size){
    int i=1;
    while(i!=size){
        swap(arr[i],arr[size]);
        size--;
        heapify(i, arr, size);
    }
}




int main(){
    vector<int> arr = {-1,7,5,4,2,1,9,3,8};
    int index = 8;

    buildHeap(index, arr);

    heapSort(arr,index);

    for(int i=1; i<=index; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}