#include <iostream>
#include <vector>
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


Node* create(Node* root){
    int val;
    cout << "Enter data: ";
    cin >> val;
    if(val==-1){
        return NULL;
    }

    root = new Node(val);
    cout << "Enter data on left side of " << val << endl;
    root -> left = create(root -> left);
    cout << "Enter data on right side of " << val << endl;
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


void saveInorder(Node* root, vector<int> &v){
    if(root==NULL){
        return;
    }
    saveInorder(root->left, v);
    v.push_back(root->data);
    saveInorder(root->right, v);
}

void convertHeap(Node* root, vector<int> &v, int &index){
    if(root==NULL){
        return;
    }
    root->data = v[index];
    index++;
    convertHeap(root->left, v, index);
    convertHeap(root->right, v, index);
}


int main(){
    Node* root = create(root);
    vector<int> v;
    int index = 0;
    saveInorder(root, v);
    convertHeap(root, v, index);
    levelOrder(root);
}