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
    vector<vector<int>> v = {{1,8,9},{2,5,10,11},{4,7}};
    vector<int> ans; 

    priority_queue<Node*, vector<Node*>, comparator> minHeap;

    int k=3;

    for(int i=0; i<k; i++){
        Node* temp = new Node(v[i][0], i, 0);
        minHeap.push(temp);   
    }

    while(!minHeap.empty()){
        Node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();
        temp->y = temp->y + 1;
        if(temp->y < v[temp->x].size()){
            temp->data = v[temp->x][temp->y];
            minHeap.push(temp);
        }
    }


    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    
    
    
}