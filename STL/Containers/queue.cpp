#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue <string> q;

    q.push("Deepak");
    q.push("Information");
    q.push("Technology");

    cout << "Size before pop:" << q.size() << endl;
    
    cout << "First element:" << q.front() << endl;
    q.pop();
    cout << "First element now:" << q.front() << endl;

    cout << "Size after pop:" << q.size() << endl;
}