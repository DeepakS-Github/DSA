#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> d;

    d.push_back(1);
    d.push_front(2);

    // d.pop_back();
    // d.pop_front();

    cout << "First Index element:" << d.at(1) << endl;

    cout << "Front element:" << d.front() << endl;
    cout << "Last element:" << d.back() << endl;

    cout << "Empty or not:" << d.empty() << endl;

    for(int i:d){
        cout << i << " ";
    }
    cout << endl;
    cout << "Size of deque before erase:" << d.size() << endl;
    d.erase(d.begin(),d.begin()+1); // Deletes first element
    cout << "Size of deque After erase:" << d.size() << endl;
    for(int i:d){
        cout << i << " ";
    }
    cout << endl;

}