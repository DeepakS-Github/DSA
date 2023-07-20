#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};


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

// O(n) time complexity

Node* solve(int inorderS, int inorderE, int &index, int inOrder[6], int preOrder[6], unordered_map<int,int> m){
    if(inorderS>inorderE){
        return NULL;
    }
    int nodeData = preOrder[index];
    Node* node = new Node(nodeData);
    index++;
    int newinorderE;
    int newinorderS;
    newinorderE = m[nodeData]-1;
    newinorderS = m[nodeData]+1;
    node -> left = solve(inorderS, newinorderE, index, inOrder, preOrder, m);
    node -> right = solve(newinorderS, inorderE, index, inOrder, preOrder, m);
    return node;
}

int main(){
    int inOrder[6]={3,1,4,0,5,2};
    int preOrder[6]={0,1,3,4,2,5};

    unordered_map<int,int> m;
    for(int i=0; i<6; i++){
        m[inOrder[i]]=i;
    }

    int index = 0;
    Node* root = solve(0, 5, index, inOrder, preOrder, m);
    levelOrder(root);

}