#include <iostream>
#include <stack>
using namespace std;

void print(stack<char> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int solve(string str){
    stack <char> st;
    if(str.size()%2!=0){
        return -1;
    }
    for(int i=0; i<str.size(); i++){
        if(str[i]=='{'){
            st.push(str[i]);
        }
        else{
            if(str[i]=='}' && !st.empty() && st.top()=='{'){
                st.pop();
            }
            else{
                st.push(str[i]);
            }
        }
    }   
    print(st);
    int open=0, closed=0;
    while(!st.empty()){
        if(st.top()=='}'){
            closed++;
            st.pop();
        }
        else if(st.top()=='{'){
            open++;
            st.pop();
        }
    }

    // Direct Formulae
    return (open+1)/2 + (closed+1)/2;
}

int main(){
    string str = "}}{}{{{}}{}}}}{{{{";
    cout << solve(str);
}