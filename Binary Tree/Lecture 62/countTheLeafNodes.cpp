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
    int d;
    cout << "Enter data: ";
    cin >> d;

    if(d == -1){
        return NULL;
    }

    root = new Node(d);

    cout << "Enter data on the left side of " << d << " : " << endl;
    root -> left = create(root -> left);

    cout << "Enter data on the right side of " << d << " : " << endl;
    root -> right = create(root -> right);

    return root;
}

void countLeaves(Node* root){
    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        if(q.front()->left!=NULL){
            q.push(q.front()->left);
        }
        if(q.front()->right!=NULL){
            q.push(q.front()->right);
        }
        if(q.front()->left==NULL && q.front()->right==NULL){
            cout << q.front()->data << " ";
        }
        q.pop();
    }
}

int main(){
    Node* root;
    create(root);
    countLeaves(root);
}