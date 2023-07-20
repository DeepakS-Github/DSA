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


void convertBSTtoArray(Node* bst, vector<Node*> &inOrder){
    if(bst==NULL){
        return;
    }
    convertBSTtoArray(bst->left, inOrder);
    inOrder.push_back(bst);
    convertBSTtoArray(bst->right, inOrder);
}


Node* createBST(vector<Node*> inOrder, int start, int end){
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    inOrder[mid]->left = createBST(inOrder, start, mid-1);
    inOrder[mid]->right = createBST(inOrder, mid+1, end);
    return inOrder[mid];
}

Node* solve(Node* bst1, Node* bst2){
    vector<Node*> inOrder1;
    vector<Node*> inOrder2;
    vector<Node*> inOrder;
    convertBSTtoArray(bst1, inOrder1);
    convertBSTtoArray(bst2, inOrder2);

    int index1 = 0;
    int index2 = 0;
    while(index1!=inOrder1.size() && index2!=inOrder2.size()-1){
        if(inOrder1[index1]->data <= inOrder2[index2]->data){
            inOrder.push_back(inOrder1[index1]);
            index1++;
        }
        else{
            inOrder.push_back(inOrder2[index2]);
            index2++;
        }
    }
    while(index1!=inOrder1.size()){
        inOrder.push_back(inOrder1[index1]);
        index1++;
    }
    while(index2!=inOrder2.size()){
        inOrder.push_back(inOrder2[index2]);
        index2++;
    }

    levelOrder(createBST(inOrder, 0, inOrder.size()-1));

}



int main(){
    Node* bst1;
    Node* bst2;
    create(bst1);
    create(bst2);
    solve(bst1, bst2);
}