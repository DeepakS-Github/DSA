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


void diagonalTraversal(Node* root){
    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        while(node!=NULL){
            if(node->left!=NULL){
                q.push(node->left);
            }
            cout << node -> data << " ";
            node = node -> right;
        }
        q.pop();
    }
}



int main(){
    Node* root;
    create(root);
    diagonalTraversal(root);
}