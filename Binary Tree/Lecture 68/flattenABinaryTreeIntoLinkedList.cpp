#include <iostream>
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

Node* create(Node* root){
    int data;
    cout << "enter data: ";
    cin >> data;
    if(data == -1){
        return NULL;
    }
    root = new Node(data);
    cout << "Enter data on the left side of " << data << " : ";
    root -> left = create(root -> left);
    cout << "Enter data on the right side of " << data << " : ";
    root -> right = create(root -> right);
    return root;
}

Node* flattenIntoLL(Node* root){
    Node* current = root;
    while(current!=NULL){
        Node* predecessor = current -> left;
        if(predecessor==NULL){
            current = current -> right;
        }
        else if(predecessor!=NULL){
            while(predecessor->right!=NULL){
                predecessor = predecessor -> right;
            }
            predecessor -> right = current -> right;
            current -> right = current -> left;
            current = current -> right;
        }
    }

    return root;
}

void printLL(Node* root){
    while(root!=NULL){
        cout << root->data << " ";
        root = root -> right;
    }
    cout << endl;
}

int main(){
    Node* root = create(NULL);
    Node* ll = flattenIntoLL(root);
    printLL(ll);
}