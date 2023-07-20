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

int kthsmallest(Node* root, int k, int &num){
    if(root == NULL){
        return 0;
    }
    
    int left = kthsmallest(root->left, k, num);
    num++;
    if(k==num){
        return root->data;
    }
    int right = kthsmallest(root->right, k, num);
    if(left!=0){
        return left;
    }
    if(right!=0){
        return right;
    }
    return 0;
    
}



int main(){
    Node* root;
    create(root);
    int num = 0;
    cout << kthsmallest(root, 1, num);
    
}