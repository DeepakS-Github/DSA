#include <iostream>
#include <stack>
#include <deque>
using namespace std;



// Time Complexity - O(row*col)

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

int largestAreaInHistogram(int arr[], int size){
    deque<int> prev;
    prevSmallerElementIndex(arr, size, prev);
    deque<int> next;
    nextSmallerElementIndex(arr, size, next);
    int area[size];
    for(int i=0; i<size; i++){
        area[i] = arr[i]*((next[i]-prev[i])-1);
    }
    int maxArea = 0;
    for(int i=0; i<size; i++){
        if(area[i]>maxArea){
            maxArea = area[i];
        }
    }
    return maxArea;
}




int main(){
    int row = 3;
    int col = 4;
    int matrix[row][col] = {{0,1,1,0},{0,0,0,0},{1,1,0,0}};
    int ar[col];
    for(int i=1; i<row; i++){
        for(int j=0; j<col; j++){
            if(matrix[i][j]!=0){
                matrix[i][j] = matrix[i][j]+matrix[i-1][j];
            }
        }
    }

    int maxArea = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            ar[j]=matrix[i][j];
        }
        int area = largestAreaInHistogram(ar, col);
        if(maxArea<area){
            maxArea = area;
        }
    }

    cout << "Size of maximum rectangle is: " << maxArea << endl;

}