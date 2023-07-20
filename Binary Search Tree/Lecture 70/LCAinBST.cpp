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


Node* lca(Node* root, int a, int b){
    if(root == NULL){
        return NULL;
    }

    if(root->data==a){
        return root;
    }
    else if(root->data==b){
        return root;
    }
    Node* node;
    if(root->data<a && root->data<b){
        node = lca(root->right, a, b);
    }
    else if(root->data>a && root->data>b){
        node = lca(root->left, a, b);
    }
    else if((root->data>a && root->data<b) || (root->data<a && root->data>b)){
        return root;
    }
    if(node!=NULL){
        return node;
    }
    return NULL;
}



int main(){
    Node* root;
    create(root);
    cout << lca(root, 10, 32)->data << endl;
    
}