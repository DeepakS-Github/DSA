#include <iostream>
#include <array>
using namespace std;

int main(){
    int normal_array[4] = {1,2,3,4};

    array<int,4> a = {1,2,3,4};
    // for(int i:a){
    //     cout << a << " ";
    // }

    cout << "Size of an array is:" << a.size() << endl;

    cout << "Element at index 2 is:" << a[2] << endl;
    cout << "Element at index 2 is:" << a.at(2) << endl;

    
    cout << endl;
}