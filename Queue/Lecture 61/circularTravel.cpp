#include <iostream>
using namespace std;

int main(){
    int size = 6;
    int petrol[size] = {6,7,4,10,6,5};
    int distance[size] = {5,6,7,8,6,4};

    int front = 0;
    int rear = 0;
    int ans = 0;

    int runLoop = 0;
    int balance = 0;
    while(runLoop!=size+1){
        runLoop++;
        if(balance + petrol[rear]-distance[rear]>=0){
            balance = balance + petrol[rear]-distance[rear];
            rear = (rear+1)%size;
        }
        else{
            front = (rear+1)%size;
            rear = (rear+1)%size;
            ans = front;
            balance = 0;
            runLoop = 0;
        }
    }

    cout << ans << endl;
}