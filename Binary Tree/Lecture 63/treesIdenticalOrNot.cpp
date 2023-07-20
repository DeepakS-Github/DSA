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

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftSide = height(root->left);
    int rightSide = height(root->right);
    return max(leftSide,rightSide)+1;
}

void identicalTrees(Node* root1, Node* root2, bool &ans){
    if(root1==NULL && root2==NULL){
        return;
    }
    if(root1==NULL && root2!=NULL){
        ans = false;
        return;
    }
    if(root1!=NULL && root2==NULL){
        ans = false;
        return;
    }
    identicalTrees(root1 -> left, root2 -> left, ans);
    identicalTrees(root2 -> right, root2 -> right, ans);
    if(root1->data!=root2->data){
        ans = false;
    }
}


int main(){
    Node* root1;
    create(root1);
    Node* root2;
    create(root2);
    bool ans = true;
    identicalTrees(root1, root2, ans);
    cout << "Is identical tree: " << ans << endl;
}