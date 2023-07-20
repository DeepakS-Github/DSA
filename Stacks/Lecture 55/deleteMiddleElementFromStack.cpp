#include <iostream>
#include <stack>
using namespace std;

void printStack(stack <int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

void deleteMiddle(stack <int> &s, int mid){
    if(mid==0){
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    deleteMiddle(s, --mid);
    s.push(temp);
}

int main(){
    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    int mid = (s.size()/2);
    deleteMiddle(s, mid);
    printStack(s);
}