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

void path(Node* root, int &count, int &sum, int req){
    if(root==NULL){
        return;
    }
    sum = sum + (root->data);
    
    if(sum>req){
        sum = sum - (root->data);
        return;
    }
    if(sum==req && root->left==NULL && root -> right==NULL){
        count++;
        sum = sum - (root->data);
        return;
    }

    path(root->left, count, sum, req);
    path(root->right, count, sum, req);
    sum = sum - (root -> data);
}

int main(){
    Node* root;
    create(root);
    int req = 8;
    int sum = 0;
    int count = 0;
    path(root, count, sum, req);
    cout << count << endl;
}