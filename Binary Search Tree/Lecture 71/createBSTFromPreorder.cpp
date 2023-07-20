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

Node* solve(Node* &root, int &index, vector<int> preOrder, int &leftLimit, int &rightLimit){
    if(index==preOrder.size()){
        return NULL;
    }
    int tempLeftLimit = leftLimit;
    int tempRightLimit = rightLimit;
    if(preOrder[index]>=leftLimit && preOrder[index]<=rightLimit){
        root = new Node(preOrder[index]);
        index++;
        rightLimit = root -> data;
        root -> left = solve(root->left, index, preOrder, leftLimit, rightLimit);
        rightLimit = tempRightLimit;
        leftLimit = root -> data;
        root -> right = solve(root->right, index, preOrder, leftLimit, rightLimit);
        leftLimit = tempLeftLimit;
    }
    return root;
}



int main(){
    Node* root;
    // create(root);
    int leftSide = INT_MIN;
    int rightSide = INT_MAX;
    vector<int> preOrder;
    preOrder.push_back(8);
    preOrder.push_back(3);
    preOrder.push_back(1);
    preOrder.push_back(6);
    preOrder.push_back(4);
    preOrder.push_back(7);
    preOrder.push_back(10);
    preOrder.push_back(14);
    preOrder.push_back(13);
    int index = 0;
    levelOrder(solve(root, index, preOrder, leftSide, rightSide));


    
}