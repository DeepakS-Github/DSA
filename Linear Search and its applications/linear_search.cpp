#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int searchElem){
    for(int i=0; i<size; i++){
        if(arr[i]==searchElem){
            return 1;
        }
    }
    return 0;
}

int main(){
    int len;
    cin >> len;
    int list[100]={0};
    for(int i=0; i<len; i++){
        cin >> list[i];
    }
    int elem;
    cin >> elem;
    int a = linearSearch(list, len, elem);
    if(a){
        cout << "Element Found" << endl;
    }
    else{
        cout << "Element Not Found" << endl;
    }

}