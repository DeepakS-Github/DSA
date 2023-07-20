#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void printQ(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void reverse(queue<int> &q, int &k){
    if(k==0){
        return;
    }
    int temp = q.front();
    q.pop();
    k--;
    reverse(q, k);
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

    int k = 2;
    int i = k;
    printQ(q);
    reverse(q, k);
    // printQ(q);

    int left = q.size()-i;    

    for(int i=0; i<left; i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

    printQ(q);

}
