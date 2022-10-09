#include <iostream>
#include <queue>
using namespace std;

int main(){
    // max-heap
    priority_queue <int> maxi;

    // min-heap
    priority_queue <int,vector<int>,greater<int>> mini;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);

    cout << "size of maxi:" << maxi.size() << endl;

    // Below line does not give correct result
    // for(int i=0; i<maxi.size(); i++){
    //     cout << maxi.top() << " ";
    //     maxi.pop();
    // }cout << endl;
    // Because after poping element size of priority queue is changing i.e. why it does not gives correct result.

    int n = maxi.size();
    // Now, below line gives correct result
    for(int i=0; i<n; i++){
        cout << maxi.top() << " ";
        maxi.pop();
    }cout << endl;

    mini.push(1);
    mini.push(3);
    mini.push(2);
    mini.push(0);

    int m = mini.size();
    // Now, below line gives correct result
    for(int i=0; i<m; i++){
        cout << mini.top() << " ";
        mini.pop();
    }cout << endl;

    cout << "Empty or not:" << mini.empty() << endl;

}