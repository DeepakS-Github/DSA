#include <iostream>
#include <stack>
using namespace std;

bool redundantBrackets(string s){
    stack <char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
            st.push(s[i]);
        }
        if(s[i]==')' && st.top()=='('){
            return true;
        }
        if(s[i]==')' && st.top()!='('){
            st.pop();
            st.pop();
        }
    }
    return false;
}

int main(){
    string str = "((((a+b)/c))*d)";
    cout << redundantBrackets(str);

}