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

void levelOrder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();  // Number of nodes at the current level

        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();

            cout << node->data << " ";

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }

        cout << endl;  // Print newline after each level
    }
}


void createVector(Node* root, vector<Node*> &v){
    if(root==NULL){
        return;
    }
    createVector(root->left, v);
    v.push_back(root);
    createVector(root->right, v);
}


Node* solve(vector<Node*> &v){
    v[v.size()]=NULL;
    for(int i=0; i<v.size()-1; i++){
        v[i]->right = v[i+1];
    }
    return v[0];
}


void printLL(Node* root){
    while(root!=NULL){
        cout << root->data << " ";
        root = root -> right;
    }
    cout << endl;
}





int main(){
    Node* root;
    create(root);
    vector<Node*> v;
    createVector(root, v);
    printLL(solve(v));

    
}