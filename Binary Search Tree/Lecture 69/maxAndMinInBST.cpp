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


void insert(Node* &root, int val){
    if(root==NULL){
        root = new Node(val);
        return;
    }
    if(root -> data > val && root -> left == NULL){
        Node* node = new Node(val);
        root -> left = node;
        return;
    }
    else if(root -> data < val && root -> right == NULL){
        Node* node = new Node(val);
        root -> right = node;
        return;
    }
    if(root->data > val){
        insert(root->left, val);
    }
    else{
        insert(root->right, val);
    }
}

void create(Node* &root){
    int data;
    cout << "Enter data: ";
    cin >> data;
    if(data==-1){
        return;
    }
    insert(root, data);
    create(root);
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

int minVal(Node* root){
    while(root -> left!=NULL){
        root = root -> left;
    }
    return root -> data;
}

int maxVal(Node* root){
    while(root -> right!=NULL){
        root = root -> right;
    }
    return root -> data;
}

int main(){
    Node* root = NULL;
    create(root);
    levelOrder(root);
    cout << minVal(root);
    cout << endl;
    cout << maxVal(root);
}