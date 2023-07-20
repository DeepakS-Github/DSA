#include <iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(){
        size = 5;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data){
        if(rear==size-1){
            cout << "Queue is full" << endl;
            return;
        }
        rear++;
        arr[rear] = data;
    }

    void pop(){
        if(rear==front){
            cout << "Queue is already empty" << endl;
            return;
        }
        front++;
        if(rear==front){
            rear = -1;
            front = -1;
        }
    }

    void print(){
        for(int i=front+1; i<=rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(6);
    q.pop();
    q.pop();
    q.print();
}