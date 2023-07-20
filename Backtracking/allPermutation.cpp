#include <iostream>
using namespace std;

void permutation(int *arr, int size, int index){
    if(index==size){
        for(int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=index; i<size; i++){
        swap(arr[index], arr[i]);
        permutation(arr, size, index+1);
        swap(arr[index], arr[i]);
    }
}

int main(){
    int arr[3] = {1,2,3};
    permutation(arr, 3, 0);
}