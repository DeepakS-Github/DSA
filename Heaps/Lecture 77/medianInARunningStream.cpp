#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1,8,9,2,5,10,11,4,7};

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<v.size(); i++){
        maxHeap.push(v[i]);
        if(minHeap.size()+1!=maxHeap.size() && maxHeap.size()!=minHeap.size()){
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
        if(!minHeap.empty() && maxHeap.top()>minHeap.top()){
            int temp1 = maxHeap.top();
            int temp2 = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(temp2);
            minHeap.push(temp1);
        }
        if(minHeap.size()+1==maxHeap.size()){
            cout << maxHeap.top() << endl;
        }
        else{
            cout << (minHeap.top()+maxHeap.top())/2.0 << endl;
        }
    }
}