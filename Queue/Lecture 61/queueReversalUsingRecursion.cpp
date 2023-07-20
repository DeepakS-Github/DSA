#include <iostream>
#include <queue>
using namespace std;

void printQ(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void reverse(queue<int> &q){
    if(q.empty()){
        return;
    }
    int temp = q.front();
    q.pop();
    reverse(q);
    q.push(temp);
}

int main(){
    queue <int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    printQ(q);
    reverse(q);
    printQ(q);

}
