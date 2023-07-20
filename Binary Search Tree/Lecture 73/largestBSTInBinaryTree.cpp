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

int solve(Node* root,bool &isBST, int &mini, int &maxi){
    if(isBST==false){
        isBST = false;
        mini = 0;
        maxi = 0;
        return 0;
    }
    if(root->left==NULL){
        isBST = true;
        mini = INT_MIN;
        maxi = 0;
        return 0;
    }
    if(root->right==NULL){
        isBST = true;
        mini = 0;
        maxi = INT_MAX;
        return 0;
    }
    int leftTree = solve(root->left, isBST, mini, maxi);
    int rightTree = solve(root->right, isBST, mini, maxi); 
    if(root->data<mini || root->data>maxi){
        isBST = false;
    }
    mini = min(root->data, mini);
    maxi = max(root->data, maxi);
    return leftTree+rightTree+1;

}

int main(){
    Node* root;
    create(root);
    cout << solve(root);
}