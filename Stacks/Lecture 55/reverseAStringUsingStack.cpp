#include <iostream>
#include <stack>
using namespace std;

void printStack(stack <char> s){
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}

int main(){
    string str = "Hello";
    stack <char> s;
    for(int i=0; i<str.length(); i++){
        s.push(str[i]);
    }
    printStack(s);
    
    
}