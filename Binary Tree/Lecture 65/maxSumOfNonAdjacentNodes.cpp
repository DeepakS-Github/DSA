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
    int data;
    cout << "Enter data: ";
    cin >> data;
    if(data == -1){
        return NULL;
    }
     
    root = new Node(data);

    cout << "Enter data on left side of " << data << " : ";
    root -> left = create(root -> left);
    cout << "Enter data on right side of " << data << " : ";
    root -> right = create(root -> right);

    return root;
}


int levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);

    int sum1=0;
    int sum2=0;

    int isOddLevel = 0;

    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            if(isOddLevel){
                sum1 = sum1 + q.front()->data;
            }
            else{
                sum2 = sum2 + q.front()->data;
            }
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }
            q.pop();
        }
        if(isOddLevel){
            isOddLevel = 0;
        }
        else{
            isOddLevel = 1;
        }
    }

    return max(sum1, sum2);
}


int main(){
    Node* root;
    create(root);
    cout << levelOrder(root);
}