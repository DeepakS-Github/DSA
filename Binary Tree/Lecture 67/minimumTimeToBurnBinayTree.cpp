#include <bits/stdc++.h>
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


void createMap(unordered_map<Node*,Node*> &m, Node* root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL){
        m[root->left]=root;
    }
    if(root->right!=NULL){
        m[root->right]=root;
    }
    createMap(m, root->left);
    createMap(m, root->right);
}

Node* targetNode(Node* root, int target){
    if(root == NULL){
        return NULL;
    }
    if(root->data == target){
        return root;
    }
    Node* left = targetNode(root->left, target);
    Node* right = targetNode(root->right, target);
    if(left!=NULL){
        return left;
    }
    else if(right!=NULL){
        return right;
    }
    return NULL;
}

int solve(unordered_map<Node*, Node*> parent, Node* root, int target){
    int time = 0;
    queue<Node*> q;
    unordered_map<Node*, bool> visited;
    Node* startNode = targetNode(root, target);
    q.push(startNode);
    visited[startNode] = true;
    bool added = false;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            if(q.front()->left!=NULL && !visited[q.front()->left]){
                q.push(q.front()->left);
                visited[q.front()->left]=true;
                added = true;
            }
            if(q.front()->right!=NULL && !visited[q.front()->right]){
                q.push(q.front()->right);
                visited[q.front()->right]=true;
                added = true;
            }
            if(q.front()!=root && !visited[parent[q.front()]]){
                q.push(parent[q.front()]);
                visited[parent[q.front()]]=true;
                added = true;
            }
            q.pop();
        }
        if(added){
            time++;
        }
        added = false;
    }

    return time;
}


int main(){
    Node* root;
    create(root);
    unordered_map<Node*, Node*> m;
    createMap(m, root);
    cout << solve(m, root, 5);

    
}