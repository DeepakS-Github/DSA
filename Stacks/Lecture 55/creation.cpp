#include <iostream>
using namespace std;

class Stack{
    public:
    int size = 10;
    int *arr = new int[size];
    int index;

    Stack(){
        index=-1;
    }

    void push(int data){
        if(index==size-1){
            cout << "Stack Overflow" << endl;
            return;
        }
        index++;
        arr[index]=data;
    }

    void pop(){
        if(index==-1){
            cout << "Stack already empty" << endl;
            return;
        }
        index--;
    }

    void print(){
        if(index==-1){
            cout << "Stack is empty" << endl;
            return;
        }
        for(int i=0; i<=index; i++){
            cout << arr[index] << " ";
        }
        cout << endl;
    }

    void top(){
        if(index==-1){
            cout << "Stack is empty" << endl;
            return;
        }
        cout << arr[index] << endl;
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(1);
    s.push(6);
    s.top();
    s.push(1);
    s.print();
    s.pop();
    s.pop();
    s.print();
    s.pop();
    s.pop();
    // s.print();
    s.pop();
    s.top();
}