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

Node* solve(int inorderS, int inorderE, int &index, int inOrder[8], int postOrder[8], unordered_map<int,int> m){
    if(inorderS>inorderE){
        return NULL;
    }
    int nodeData = postOrder[index];
    Node* node = new Node(nodeData);
    index--;
    int newinorderE;
    int newinorderS;
    newinorderE = m[nodeData]-1;
    newinorderS = m[nodeData]+1;
    node -> right = solve(newinorderS, inorderE, index, inOrder, postOrder, m);
    node -> left = solve(inorderS, newinorderE, index, inOrder, postOrder, m);
    return node;
}

int main(){
    int inOrder[8]={4,8,2,5,1,6,3,7};
    int postOrder[8]={8,4,5,2,6,7,3,1};

    unordered_map<int,int> m;
    for(int i=0; i<8; i++){
        m[inOrder[i]]=i;
    }

    int index = 7;
    Node* root = solve(0, 7, index, inOrder, postOrder, m);
    levelOrder(root);

}