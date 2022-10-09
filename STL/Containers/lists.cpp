#include <iostream>
#include <list>
using namespace std;

int main(){
    list <int> l;
    list <int> newList(l);  // Copy 'l' list in new list 'newList'
    list <int> n(5,100);    // Create list of size 5 with every element 100 initialized

    cout << "Printing n" << endl;
    for(int i:n){
        cout << i << " ";
    }
    cout << endl;

    l.push_back(1);
    l.push_front(2);

    for(int i:l){
        cout << i << " ";
    }
    cout << endl;

    l.erase(l.begin());     //l.begin() -> Returns an iterator      // Deletes 1st element
    cout << "after erase" << endl;
    for(int i:l){
        cout << i << " ";
    }
    cout << endl;

    cout << "Size of list is:" << l.size() << endl;

}