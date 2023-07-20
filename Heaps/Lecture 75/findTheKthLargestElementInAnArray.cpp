#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int k = 3;
    vector<int> v = {7,10,4,3,2,15};

    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        pq.push(v[i]);
    } 

    for(int i=k; i<v.size(); i++){
        if(pq.top()>v[i]){
            pq.pop();
            pq.push(v[i]);
        }
    }

    cout << pq.top() << endl;
}