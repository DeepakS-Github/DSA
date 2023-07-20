#include <iostream>
#include <queue>
using namespace std;

// Morris Traversal is like BFS, done using iterative in O(N) time and O(1) space

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


void morrisTraversal(Node* root){
    Node* current = root;
    while(current!=NULL){
        Node* predecessor = current -> left;
        if(predecessor == NULL){
            cout << current->data << " ";
            current = current -> right;
        }
        else{
            while(predecessor->right!=NULL && predecessor->right!=current){
                predecessor = predecessor -> right;
            }
            if(predecessor->right==NULL){
                predecessor -> right = current;
                current = current -> left;
            }
            else{
                predecessor -> right = NULL;
                cout << current -> data << " ";
                current = current -> right;
            }
        }
    }
}


int main(){
    Node* root;
    create(root);
    morrisTraversal(root);
}