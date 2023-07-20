#include <iostream>
#include <queue>
#include <map>
#include <vector>
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


void topLevel(Node* root, map<int, int> &m){
    queue<pair<Node*, int>> q;

    q.push(make_pair(root, 0));

    while(!q.empty()){
        m[q.front().second] = q.front().first->data;
        if(q.front().first -> left!=NULL){
            q.push(make_pair(q.front().first -> left, q.front().second-1));
        }
        if(q.front().first -> right!=NULL){
            q.push(make_pair(q.front().first -> right, q.front().second+1));
        }
        q.pop();
    }

}



int main(){
    Node* root;
    create(root);
    map<int,int> m;
    topLevel(root, m);

    for (const auto& pair : m) {
        int value = pair.second;

        cout << value << " " ;
    }
    
}