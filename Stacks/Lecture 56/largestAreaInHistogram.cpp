#include <iostream>
#include <deque>
#include <stack>
using namespace std;

// Time Complexity - O(n)

void prevSmallerElementIndex(int arr[], int size, deque<int> &d){
    stack <int> st;
    for(int i=0; i<size; i++){
        if(st.empty()){
            st.push(i);
            d.push_back(-1);
        }
        else if(arr[i]>arr[st.top()]){
            d.push_back(st.top());
            st.push(i);
        }
        else if(arr[i]<=arr[st.top()]){
            while(arr[i]<=arr[st.top()]){
                st.pop();
                if(st.empty()){
                    break;
                }
            }
            if(st.empty()){
                d.push_back(-1);
                st.push(i);
            }
            else{
                d.push_back(st.top());
                st.push(i);
            }
        }
    }
}

void nextSmallerElementIndex(int arr[], int size, deque<int> &d){
    stack <int> st;
    for(int i=size-1; i>=0; i--){
        if(st.empty()){
            d.push_front(size);
            st.push(i);
        }
        else if(arr[st.top()]<arr[i]){
            d.push_front(st.top());
            st.push(i);
        }
        else if(arr[st.top()]>=arr[i]){
            while(arr[st.top()]>=arr[i]){
                st.pop();
                if(st.empty()){
                    break;
                }
            }
            if(st.empty()){
                d.push_front(size);
                st.push(i);
            }
            else{
                d.push_front(st.top());
                st.push(i);
            }
        }
    }
}

int main(){
    int arr[6] = {0,1,1,0,0,0};
    deque<int> prev;
    prevSmallerElementIndex(arr, 6, prev);
    for(int i=0; i<prev.size(); i++){
        cout << prev[i] << " ";
    }
    cout << endl;
    deque<int> next;
    nextSmallerElementIndex(arr, 6, next);
    for(int i=0; i<next.size(); i++){
        cout << next[i] << " ";
    }
    int area[6];
    for(int i=0; i<6; i++){
        area[i] = arr[i]*((next[i]-prev[i])-1);
    }
    cout << endl;
    int maxArea = 0;
    for(int i=0; i<6; i++){
        if(area[i]>maxArea){
            maxArea = area[i];
        }
        cout << area[i] << " ";
    }
    cout << endl;
    cout << "Maximum area in a histogram is: " << maxArea << endl;
}

