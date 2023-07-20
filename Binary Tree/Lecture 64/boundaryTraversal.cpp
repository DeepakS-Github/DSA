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

void leftSide(Node* root){
    if(root -> left == NULL){
        return;
    }
    cout << root -> data << " ";
    leftSide(root -> left);
}

void bottomSide(Node* root){
    if(root == NULL){
        return;
    }
    bottomSide(root -> left);
    if(root -> left == NULL && root -> right == NULL){
        cout << root -> data << " ";
    }
    bottomSide(root -> right);
}

void rightSide(Node* root){
    if(root -> right == NULL){
        return;
    }
    rightSide(root -> right);
    cout << root -> data << " ";
}


int main(){
    Node* root;
    create(root);
    leftSide(root);
    bottomSide(root);
    rightSide(root->right);
}