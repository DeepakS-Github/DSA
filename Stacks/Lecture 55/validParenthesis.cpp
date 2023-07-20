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
    string str = "()";
    stack <char> s;
    for(int i=0; i<str.length(); i++){
        if(str[i]=='[' || str[i]=='(' || str[i]=='{'){
            s.push(str[i]);
        }
        else if(!s.empty() && ((str[i]==')' && s.top()=='(') || (str[i]==']' && s.top()=='[') || (str[i]=='}' && s.top()=='{'))){
            s.pop();
        }
        else{
            s.push(str[i]);
        }
    }
    if(s.empty()){
        cout << "Balanced" << endl;
    }
    else{
        cout << "Not Balanced" << endl;
    }
}