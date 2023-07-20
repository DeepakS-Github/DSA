#include <iostream>
#include <stack>
using namespace std;

void printStack(stack <char> s){
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}


void insert(stack<char> &s, int length, int data){
    if(!length){
        s.push(data);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, length-1, data);
    s.push(temp);
}

void reverse(stack<char> &s){
    int i = s.size();
    while(i!=1){
        insert(s, i--, s.top());
        s.pop();
    }
}


int main(){
    string str = "Hello";
    stack <char> s;
    for(int i=0; i<str.length(); i++){
        s.push(str[i]);
    }
    reverse(s);
    printStack(s);
}