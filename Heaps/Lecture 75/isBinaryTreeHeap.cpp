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
    int val;
    cout << "Enter data: ";
    cin >> val;
    if(val==-1){
        return NULL;
    }

    root = new Node(val);
    cout << "Enter data on left side of " << val << endl;
    root -> left = create(root -> left);
    cout << "Enter data on right side of " << val << endl;
    root -> right = create(root -> right);
    
    return root;
}

void count(Node* root, int &cnt){
    if(root==NULL){
        return;
    }
    cnt++;
    count(root->left, cnt);
    count(root->right, cnt);
}


bool isCBT(Node* root, int i, int nodes){
    if(root==NULL){
        return true;
    }
    if(i>nodes){
        return false;
    }
    bool leftCheck = isCBT(root->left, 2*i, nodes);
    bool rightCheck = isCBT(root->right, 2*i+1, nodes);
    if(leftCheck==false || rightCheck==false){
        return false;
    }
    return true;
}

bool isHeap(Node* root){
    if(root==NULL){
        return true;
    }
    if((root->left!=NULL && root->left->data>root->data) || (root->right!=NULL && root->right->data>root->data)){
        return false;
    }
    bool left = isHeap(root->left);
    bool right = isHeap(root->right);
    if(left==false || right==false){
        return false;
    }
    return true;
}


int main(){
    Node* root = create(root);
    int num = 0;
    count(root, num);
    if(isCBT(root,1,num)){
        cout << isHeap(root);
    }
    else{
        cout << false;
    }
}