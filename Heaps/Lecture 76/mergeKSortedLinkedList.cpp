#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};

class comparator{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

void print(Node* head){
    while(head!=NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}



int main(){
    // Linked List Creation
    Node* arr1 = new Node(1);
    Node* arr11 = new Node(8);
    Node* arr12 = new Node(9);
    arr1 -> next = arr11;
    arr11 -> next = arr12;

    Node* arr2 = new Node(2);
    Node* arr21 = new Node(5);
    Node* arr22 = new Node(10);
    Node* arr23 = new Node(11);
    arr2 -> next = arr21;
    arr21 -> next = arr22;
    arr22 -> next = arr23;

    Node* arr3 = new Node(4);
    Node* arr31 = new Node(7);
    arr3 -> next = arr31;

    // Main solution starts here

    int k = 3;
    Node* v[k] = {arr1, arr2, arr3};

    for(int i=0; i<k; i++){
        print(v[i]);
    }

    priority_queue<Node*, vector<Node*>, comparator> minHeap;

    Node* head = new Node(1);
    Node* tail = head;

    for(int i=0; i<k; i++){
        minHeap.push(v[i]);
    }

    while(!minHeap.empty()){
        tail -> next = minHeap.top();
        tail = tail -> next;
        Node* temp = minHeap.top();
        minHeap.pop();

        if(temp->next!=NULL){
            minHeap.push(temp->next);
        }
    }

    print(head->next);

    

    



    
}