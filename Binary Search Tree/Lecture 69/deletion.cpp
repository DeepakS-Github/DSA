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

int getSuccessor(Node* root){
    if(root->right->left==NULL){
        int temp = root->right->data;
        root -> right = NULL;
        return temp;
    }
    root = root -> right;
    while(root->left->left!=NULL){
        root = root -> left;
    }
    int successor =  root->left->data;
    root -> left = root -> left -> right;
    return successor;
}

void deletion(Node* &root, int todelete){
    Node* ptr = root;
    Node* parent = root;
    while(ptr->data != todelete){
        parent = ptr;
        if(ptr->data>todelete){
            ptr = ptr -> left;
        }
        else{
            ptr = ptr -> right;
        }
    }
    if(ptr->left==NULL && ptr->right==NULL){
        if(parent->left == ptr){
            parent -> left = NULL;
        }
        else{
            parent -> right = NULL;
        }
    }
    else{
        ptr->data = getSuccessor(ptr);
    }
}


int main(){
    Node* root;
    create(root);
    deletion(root, 6);
    levelOrder(root);
}