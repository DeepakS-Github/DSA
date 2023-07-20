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

Node* targetNode(Node* root, int target){
    if(root==NULL){
        return NULL;
    }
    if(root -> data == target){
        return root;
    }
    Node* left = targetNode(root->left, target);
    Node* right = targetNode(root->right, target);
    if(left!=NULL){
        return left;
    }
    if(right!=NULL){
        return right;
    }
    return NULL;
}

Node* inorderSuccessor(Node* root, int target){
    if(root==NULL){
        return NULL;
    }
    Node* getNode = targetNode(root, target);
    if(getNode->right!=NULL){
        getNode = getNode -> right;
        while(getNode->left!=NULL){
            getNode = getNode -> left;
        }
    }
    return getNode;
}

Node* inorderPredecessor(Node* root, int target){
    if(root==NULL){
        return NULL;
    }
    Node* getNode = targetNode(root, target);
    if(getNode->left==NULL){
        return getNode;
    }
    return getNode->left;
}



int main(){
    Node* root;
    create(root);
    int target = 35;
    cout << inorderPredecessor(root, target)->data << endl;
    cout << inorderSuccessor(root, target)->data << endl;
}