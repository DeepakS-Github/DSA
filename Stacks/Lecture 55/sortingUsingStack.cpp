#include <iostream>
#include <stack>
using namespace std;

void printStack(stack <int> s){
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}

void arrange(stack<int> &s, int elem){
    if(s.empty() || s.top()>=elem){
        s.push(elem);
        return;
    }
    int temp = s.top();
    s.pop();
    arrange(s, elem);
    s.push(temp);
}

void sort(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    sort(s);
    arrange(s, temp);
}

int main(){
    stack <int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);
    sort(s);
    printStack(s);
}