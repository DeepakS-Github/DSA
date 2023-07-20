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

bool checkValidBST(Node* root, int &leftRange, int &rightRange){
    if(root==NULL){
        return true;
    }
    if(root->data < leftRange || root -> data > rightRange){
        return false;
    }
    int tempLeftRange = leftRange;
    int tempRightRange = rightRange;
    rightRange = root->data;
    bool left = checkValidBST(root->left, leftRange, rightRange);
    rightRange = tempRightRange;
    leftRange = root -> data;
    bool right = checkValidBST(root->right, leftRange, rightRange);
    leftRange = tempLeftRange;
    rightRange = tempRightRange;
    if(left==false || right==false){
        return false;
    }
    return true;
}

int main(){
    Node* root;
    create(root);
    int leftRange = INT_MIN;
    int rightRange = INT_MAX;
    cout << checkValidBST(root, leftRange, rightRange);
}