#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<string> s;

    s.push("Deepak");
    s.push("Information");
    s.push("Technology");

    cout << "Top element:" << s.top() << endl;
    s.pop();
    cout << "Now top element:" << s.top() << endl;
    
    cout << "Size of stack:" << s.size() << endl;

    cout << "Empty or not:" << s.empty() << endl;
}