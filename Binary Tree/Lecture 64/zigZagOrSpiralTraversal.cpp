#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* create(Node* &root){
    int data;
    cout << "Enter data: ";
    cin >> data;
    if(data == -1){
        return NULL;
    }
     
    root = new Node(data);

    cout << "Enter data on left side of " << data << " : ";
    root -> left = create(root -> left);
    cout << "Enter data on right side of " << data << " : ";
    root -> right = create(root -> right);

    return root;
}

void printDeque(deque<int> &dq){
    while(!dq.empty()){
        cout << dq.front() << " ";
        dq.pop_front();
    }
}

void zigZag(Node* root){
    queue<Node*> q;
    deque<int> dq;
     
    q.push(root);

    bool leftToRight = false;

    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            if(leftToRight){
                dq.push_front(q.front()->data);
            }
            else{
                dq.push_back(q.front()->data);
            }
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }
            q.pop();
        }
        printDeque(dq);
        if(leftToRight){
            leftToRight = false;
        }
        else{
            leftToRight = true;
        }
    }
}

int main(){
    Node* root;
    create(root);
    zigZag(root);
}