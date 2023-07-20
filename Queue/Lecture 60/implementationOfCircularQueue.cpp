#include <iostream>
using namespace std;

class Queue{
    public:
    int size;
    int *arr;
    int front;
    int rear;

    Queue(){
        size = 5;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data){
        if(rear%size==front%size){
            cout << "Queue is full" << endl;
            return;
        }
        rear = rear + 1;
        arr[rear%size]=data;
    }

    void pop(){
        if(front%size == rear%size){
            cout << "Queue is already empty" << endl;
            return;
        }
        front = (front+1)%size;
        if(front%size == rear%size){
            front = -1;
            rear = -1;
        }
    }

    void print(){
        if(front<rear){
            for(int i=(front+1)%size; i<=(rear)%size; i++){
                cout << arr[i] << " ";
            }   
            cout << endl;
        }
        else{
            for(int i=rear%size; i<=(front+1)%size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void printArr(){
        for(int i=0; i<5; i++){
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
    q.push(7);
    q.print();
    q.printArr();
}