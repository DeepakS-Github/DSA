#include <iostream>
#include <stack>
#include <deque>
using namespace std;

void showdq(deque<int> g){
    deque<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
    cout << ' ' << *it;
    cout << '\n';
}

void solve(int arr[], int size, deque<int> d){
    stack <int> st;
    st.push(-1);
    for(int i=size-1; i>=0; i--){
        if(arr[i]>st.top()){
            d.push_front(st.top());
            st.push(arr[i]);
        }
        else if(arr[i]<=st.top()){
            while(st.top()>=arr[i]){
                st.pop();
            }
            d.push_front(st.top());
            st.push(arr[i]);
        }
    }
    showdq(d);
}

int main(){
    
    int arr[5] = {4,2,1,8,5};
    deque<int> d;
    solve(arr, 5, d);
}