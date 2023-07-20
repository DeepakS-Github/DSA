#include <iostream>
#include <stack>
using namespace std;

void solveStack(stack<int> st, stack<int> &ans){
    if(st.size()==1){
        ans.push(st.top());
        return;
    }
    int temp = st.top();
    st.pop();
    solveStack(st, ans);
    int minimum = min(temp, st.top());
    ans.push(minimum);
}

int main(){
    int size = 5;
    int arr[size]={4,2,8,3,5};

    stack <int> st;
    for(int i=size-1; i>=0; i--){
        st.push(arr[i]);
    }

    stack <int> ans;
    solveStack(st, ans);

    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }

}