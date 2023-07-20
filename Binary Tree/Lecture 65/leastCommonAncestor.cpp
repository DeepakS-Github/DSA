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


int solve(Node* root, int d1, int d2){
    if(root == NULL){
        return 0;
    }
    int left = solve(root->left, d1, d2);
    int right = solve(root->right, d1, d2);
    if(root->data==d1 || root->data==d2){
        return root->data;
    }
    if(left!=0 && right!=0){
        return root->data;
    }
    if(left!=0 || right!=0){
        if(left!=0){
            return left;
        }
        return right;
    }
    return 0;
}

int main(){
    Node* root;
    create(root);
    int d1 = 5;
    int d2 = 7;
    cout << solve(root, d1, d2);
}