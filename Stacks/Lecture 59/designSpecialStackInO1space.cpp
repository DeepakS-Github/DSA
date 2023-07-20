#include <iostream>
#include <stack>
using namespace std;




int main(){
    int size = 5;
    int arr[size]={4,2,8,3,5};

    stack <int> st;
    int mini = arr[size-1];
    for(int i=size-1; i>=0; i--){
        if(arr[i]<mini){
            int val = 2*arr[i]-mini;
            st.push(val);
            mini = arr[i];
        }
        else{
            st.push(arr[i]);
        }
    }

    cout << mini << " ";
    while(st.size()!=1){
        if(st.top()>mini){
            cout << mini << " ";
            st.pop();
        }
        else{
            int val = 2*mini-st.top();
            mini = val;
            cout << val << " ";
            st.pop();
        }
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }



    

}