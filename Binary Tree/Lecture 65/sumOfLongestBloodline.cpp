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


void solve(Node* root, int &height, int &sum, int &maxheight, int &maxsum){
    if(root == NULL){
        return;
    }
    height = height+1;
    if(height>=maxheight){
        maxheight = height;
        sum = sum + (root->data);
        if(sum>=maxsum){
            maxsum = sum;
        }
    }   
    solve(root->left, height, sum, maxheight, maxsum);
    solve(root->right, height, sum, maxheight, maxsum);
    height = height-1;
    sum = sum-(root->data);
}

int main(){
    Node* root;
    create(root);
    int height = 0;
    int sum = 0;
    int maxheight = INT_MIN;
    int maxsum = INT_MIN;
    solve(root, height, sum, maxheight, maxsum);
    cout << maxheight << " " << maxsum << endl;
}