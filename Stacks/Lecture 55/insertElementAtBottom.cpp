#include <iostream>
#include <stack>
using namespace std;

void printStack(stack <char> s){
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
}

void insertElementAtBottom(stack <char> &s, char top){
    if(s.empty()){
        s.push(top);
        return;
    }
    int temp = s.top();
    s.pop();
    insertElementAtBottom(s, top);
    s.push(temp);
}

int main(){
    string str = "olleh";
    stack <char> s;
    for(int i=0; i<str.length(); i++){
        s.push(str[i]);
    }
    insertElementAtBottom(s, s.top());
    s.pop();
    printStack(s);

    
    
}