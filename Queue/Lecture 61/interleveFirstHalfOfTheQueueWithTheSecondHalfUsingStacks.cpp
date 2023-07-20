#include <iostream>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

void print(queue<int> q, stack<int> halfQueue){
    cout << "Stack: " << endl;
    while(!halfQueue.empty()){
        cout << halfQueue.top() << " ";
        halfQueue.pop();
    }

    cout << endl;
    cout << "Queue: " << endl;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main(){
    int size = 4;
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    // q.push(5);

    int half = ceil(float(q.size())/2);
    int remaining = q.size() - half;

    stack <int> halfQueue;
    for(int i=0; i<half; i++){
        halfQueue.push(q.front());
        q.pop();
    }

    

    while(!halfQueue.empty()){
        q.push(halfQueue.top());
        halfQueue.pop();
    }

    for(int i=0; i<remaining; i++){
        q.push(q.front());
        q.pop();
    }

    for(int i=0; i<half; i++){
        halfQueue.push(q.front());
        q.pop();
    }

    print(q,halfQueue);

    int arr[size];
    int i=0;
    while(!q.empty() || !halfQueue.empty()){
        if(!halfQueue.empty()){
            arr[i++] = halfQueue.top();
            halfQueue.pop();
        }
        if(!q.empty()){
            arr[i++] = q.front();
            q.pop();
        }
        
    }

    for(int j=0; j<size; j++){
        cout << arr[j] << " ";
    }
    cout << endl;
    


}