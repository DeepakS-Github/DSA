#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    vector<int> v1(5);   //-> Vector of size 5 is created and every element is 0 assigned;
    vector<int> v2(5,1); //-> Vector of size 5 is created and every element is 1 assigned;


    cout << "Capacity:" << v.capacity() << endl;
    cout << "Size:" << v.size() << endl;

    v.push_back(1);
    cout << "Capacity:" << v.capacity() << endl;
    cout << "Size:" << v.size() << endl;

    v.push_back(2);
    cout << "Capacity:" << v.capacity() << endl;
    cout << "Size:" << v.size() << endl;

    v.push_back(3);
    cout << "Capacity:" << v.capacity() << endl;    // See how capacity of vector is getting doubled. For more details refer to copy.
    cout << "Size:" << v.size() << endl;
    // Here capacity is 4 but size is 3.

    //--------------------------------------------------------------------------------------------------------------------

    cout << "Element at 2nd Index:" << v.at(2) << endl;
    cout << "Element at 2nd Index:" << v[2] << endl;

    //--------------------------------------------------------------------------------------------------------------------

    cout << "Front element:" << v.front() << endl;
    cout << "Last element:" << v.back() << endl;

    //--------------------------------------------------------------------------------------------------------------------

    cout << "Before pop" << endl;
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;

    v.pop_back();

    cout << "After pop" << endl;
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;

    cout << "Capacity of array after pop is:" << v.capacity() << endl;
    cout << "Size of array after pop is:" << v.size() << endl;

    //--------------------------------------------------------------------------------------------------------------------

    v.clear();
    cout << "After clear" << endl;
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;

    cout << "Capacity of array after clear is:" << v.capacity() << endl;
    cout << "Size of array after clear is:" << v.size() << endl;


}