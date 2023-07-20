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


void createVector(Node* root, vector<int> &v){
    if(root==NULL){
        return;
    }
    createVector(root->left, v);
    v.push_back(root->data);
    createVector(root->right, v);
}


void solve(int target, int &a, int &b, vector<int> v){
    a = 0;
    b = v.size()-1;
    while((v[a]+v[b])!=target){
        if(target>(v[a]+v[b])){
            a++;
        }
        else if(target<(v[a]+v[b])){
            b--;
        }
    }
}





int main(){
    Node* root;
    create(root);
    int a;
    int b;
    vector<int> v;
    int target = 40;
    createVector(root, v);
    solve(target, a, b, v);
    cout << v[a] << " " << v[b] << endl;

    
}