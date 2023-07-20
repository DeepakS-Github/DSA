#include <iostream>
#include <stack>
using namespace std;

// In Postorder, Morris Traversal is like BFS, done using iterative in O(N) time and O(N) space

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


void morrisTraversal(Node* root){
    stack <int> st;
    Node* current = root;
    while(current!=NULL){
        Node* predecessor = current -> right;
        if(predecessor == NULL){
            st.push(current->data);
            current = current -> left;
        }
        else{
            while(predecessor->left!=NULL && predecessor->left!=current){
                predecessor = predecessor -> left;
            }
            if(predecessor->left==NULL){
                st.push(current->data);
                predecessor -> left = current;
                current = current -> right;
            }
            else{
                predecessor -> left = NULL;
                current = current -> left;
            }
        }
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}


int main(){
    Node* root;
    create(root);
    morrisTraversal(root);
}