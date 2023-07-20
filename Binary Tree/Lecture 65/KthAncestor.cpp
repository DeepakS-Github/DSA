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


int solve(Node* root, int &k, int target){
    if(root==NULL){
        return 0;
    }

    if(root -> data == target){
        return root->data;
    }
    
    int left = solve(root->left, k, target);
    int right = solve(root->right, k, target);

    if(k==0){
        if(left!=0){
            return left;
        }
        return right;
    }

    if(left!=0 || right!=0){
        k--;
        return root->data;
    }
    return 0;
}



int main(){
    Node* root;
    create(root);
    int k=2;
    int target = 4;
    cout << solve(root, k, target);
}