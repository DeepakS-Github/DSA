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


Node* solve(vector<Node*> v, int s, int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    v[mid]->left = solve(v, s, mid-1);
    v[mid]->right = solve(v, mid+1, e);
    return v[mid];
}






int main(){
    Node* root;
    create(root);
    vector<Node*> v;
    createVector(root, v);
    levelOrder(solve(v,0,6));    
}