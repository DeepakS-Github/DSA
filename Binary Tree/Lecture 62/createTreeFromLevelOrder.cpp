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

void buildTree(Node* &root){
    queue <Node*> q;
    int data;
    cout << "Enter root data: ";
    cin >> data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()){
        int leftData, rightData;
        Node* leftNode;
        Node* rightNode;


        cout << "Enter data at left of " << q.front()->data << " : ";
        cin >> leftData;
        
        if(leftData!=-1){
            leftNode = new Node(leftData);
        }
        
        cout << "Enter data at right of " << q.front()->data << " : ";
        cin >> rightData;
        if(rightData != -1){
            rightNode = new Node(rightData);
        }

        if(leftData!=-1){
            q.front()->left=leftNode;
            q.push(leftNode);
        }
        if(rightData!=-1){
            q.front()->right=rightNode;
            q.push(rightNode);
        }
        q.pop();
    }
}

int main(){
    Node* root;
    buildTree(root);
    levelOrder(root);
}