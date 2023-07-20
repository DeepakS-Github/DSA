#include <iostream>
#include <stack>
using namespace std;

// Time Complexity - O(n)

void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main(){
    int size = 2;
    int arr[2][2]={{0,1},{1,0}};
    stack <int> st;
    for(int i=0; i<size; i++){
        st.push(i);
    }
    while(st.size()>1){
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        if(!arr[first][second]){
            st.push(first);
        }
        if(!arr[second][first]){
            st.push(second);
        }
    }


    if(st.empty()){
        cout << "No one is the celebrity" << endl;
        return 0;
    }

    int left = st.top();
    for(int i=0; i<size; i++){
        if(arr[left][i]==1){
            cout << "No one is the celebrity" << endl;
            return 0;
        }
        if(arr[i][left]==0 && left!=i){
            cout << "No one is the celebrity" << endl;
            return 0;
        }
    }

    cout << st.top() << " is the celebrity" << endl;

    


}