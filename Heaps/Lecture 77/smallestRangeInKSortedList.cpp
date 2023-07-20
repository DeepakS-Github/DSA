#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    int x;
    int y;

    Node(int data, int x, int y){
        this -> data = data;
        this -> x = x;
        this -> y = y;
    }
};

class comparator{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

int main(){
    vector<vector<int>> v = {{1,2},{3,4},{5,6}};
    priority_queue<Node*, vector<Node*>, comparator> minHeap;

    int k=3;

    pair<int,int> range;

    int maxi = INT_MIN;
    for(int i=0; i<k; i++){
        if(maxi<v[i][0]){
            maxi = v[i][0];
        }
        Node* temp = new Node(v[i][0], i, 0);
        minHeap.push(temp);
    }

    range.first = minHeap.top()->data;
    range.second = maxi;

    pair<int, int> dummy;
    dummy.first = range.first;
    dummy.second = range.second;

    while(!minHeap.empty()){
        cout << 0 << endl;
        Node* temp = minHeap.top();
        minHeap.pop();
        if(temp->y+1<v[temp->x].size()){
            temp = new Node(v[temp->x][temp->y+1], temp->x, temp->y+1);
            if(v[temp->x][temp->y+1]>dummy.second){
                dummy.second = v[temp->x][temp->y+1];
            }
            minHeap.push(temp);
        }
        else{
            break;
        }
        dummy.first = minHeap.top()->data;
        cout << dummy.second - dummy.first;
        if(dummy.second-dummy.first < range.second-range.first){
            range.first = dummy.first;
            range.second = dummy.second;
        }
    }

    cout << range.first << " " << range.second << endl;
} 